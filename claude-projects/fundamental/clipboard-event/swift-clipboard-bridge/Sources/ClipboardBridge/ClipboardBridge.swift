// The Swift Programming Language
// https://docs.swift.org/swift-book

import AppKit

public class ClipboardMonitor {
    public static func getContent() -> UnsafeMutablePointer<CChar>? {
        let clipboard = NSPasteboard.general
        let string = clipboard.string(forType: .string)
        return strdup(string)
    }
}

@_cdecl("getClipboardContent")
func getClipboardContent() -> UnsafeMutablePointer<CChar>? {
    return ClipboardMonitor.getContent()
}
