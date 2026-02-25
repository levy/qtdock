# QtDock Gesture Reference

## Menu / Keyboard

| Action | Shortcut | Description |
|--------|----------|-------------|
| New | Ctrl+N | Creates a new document tab |
| Exit | Ctrl+Q | Quits the application |

## Tabbed State (multiple documents in one tab group)

| Gesture | Result |
|---------|--------|
| Click a tab | Switches to that document |
| Drag a tab horizontally within the tab bar | Reorders tabs |
| Drag a tab to the **top edge** of the tab group | Splits vertically — new document docks **above** |
| Drag a tab to the **bottom edge** of the tab group | Splits vertically — new document docks **below** |
| Drag a tab to the **left edge** of the tab group | Splits horizontally — new document docks **left** |
| Drag a tab to the **right edge** of the tab group | Splits horizontally — new document docks **right** |
| Drag a tab **outside** the main window | Tears the document off into a **floating window** |
| Click the **close button** on a tab / title bar | Closes that document |

## Split State (documents in separate panes)

| Gesture | Result |
|---------|--------|
| Drag a dock title bar onto **another pane's tab bar** | Merges the document into that tab group |
| Drag a dock title bar to an **edge of another pane** | Creates a new split adjacent to that pane |
| Drag a dock title bar **outside** the main window | Converts the pane into a floating window |
| Drag the **splitter handle** between panes | Resizes adjacent panes |
| Close the last document in a split pane | Removes that pane; remaining panes expand to fill the space |

## Floating Window State (document in its own top-level window)

| Gesture | Result |
|---------|--------|
| Drag the floating window's **title bar onto a tab bar** in the main window | Re-docks as a tab in that group |
| Drag the floating window's **title bar to an edge** of a docked pane | Re-docks as a new split |
| Drag the floating window's **title bar to an edge** of the main window | Docks to that side of the main window |
| Drag the floating window's **title bar onto another floating window** | Tabifies the two floating windows together |
| **Double-click** the floating window's title bar | Toggles between floating and last docked position (Qt default behavior) |
| Close the floating window via its **close button** or **Alt+F4** | Closes the document |
| Resize the floating window by its **edges/corners** | Standard window resize |

## Title Bar Context Menu (right-click on dock title bar)

| Action | Description |
|--------|-------------|
| Close | Closes the document |
| Float | Toggles floating state |
| Move to... | Offered by Qt in some configurations to move to a specific dock area |

## Notes

- **Nested splitting** is enabled, so you can split a split to create arbitrary grid-like layouts.
- When dragging, Qt shows a **blue overlay indicator** highlighting where the document will land.
- All gestures are provided by Qt's built-in `QDockWidget` + `QMainWindow` docking framework.
