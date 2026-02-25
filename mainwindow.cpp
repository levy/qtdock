#include "mainwindow.h"
#include <QMenuBar>
#include <QApplication>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("QtDock");
    setDockOptions(AnimatedDocks | AllowNestedDocks | AllowTabbedDocks);
    setDockNestingEnabled(true);

    // No central widget — dock widgets fill the entire window
    takeCentralWidget();
    setMinimumSize(200, 150);

    QMenu *fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&New", QKeySequence::New, this, &MainWindow::newDocument);
    fileMenu->addAction("E&xit", QKeySequence::Quit, qApp, &QApplication::quit);

    resize(1024, 768);
}

void MainWindow::newDocument()
{
    m_docCount++;

    auto *dock = new QDockWidget(tr("Document %1").arg(m_docCount), this);
    dock->setFeatures(QDockWidget::DockWidgetClosable |
                      QDockWidget::DockWidgetMovable |
                      QDockWidget::DockWidgetFloatable);

    auto *editor = new QTextEdit(dock);
    editor->setPlaceholderText(tr("Document %1").arg(m_docCount));
    editor->setMinimumSize(50, 50);
    dock->setWidget(editor);

    // Use native window frame when floating so dragging works on Wayland/Linux
    connect(dock, &QDockWidget::topLevelChanged, this, [dock](bool floating) {
        if (floating) {
            dock->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
            dock->show();
        }
    });

    addDockWidget(Qt::TopDockWidgetArea, dock);

    // Find the dock widget that currently has focus
    QDockWidget *target = nullptr;
    QWidget *focused = QApplication::focusWidget();
    while (focused) {
        if (auto *dw = qobject_cast<QDockWidget *>(focused)) {
            target = dw;
            break;
        }
        focused = focused->parentWidget();
    }

    // Fall back to the first non-floating dock widget
    if (!target) {
        for (QDockWidget *existing : findChildren<QDockWidget *>()) {
            if (existing != dock && !existing->isFloating()) {
                target = existing;
                break;
            }
        }
    }

    if (target && target != dock)
        tabifyDockWidget(target, dock);

    dock->raise();
}
