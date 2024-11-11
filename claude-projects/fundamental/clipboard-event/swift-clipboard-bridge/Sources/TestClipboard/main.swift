import ClipboardBridge

print("Clipboard Monitor Test")
print("Copy some text and watch the changes!")

if let content = ClipboardMonitor.getContent() {
    let string = String(cString: content)
    print("Initial clipboard content: \(string)")
}
