| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Process (**Internal use only**)

## verbs

| Verb      | Windows    | macOS       | linux      | Remarks                                          |
|-----------|------------|-------------|------------|--------------------------------------------------|
| ""        | "open"     | "open"      | "xdg-open" |                                                  |
| "edit"    | "edit"     | "TextEdit"  | "gedit"    |                                                  | 
| "explore" | "explore"  | "open"      | "xdg-open" | for macOS and linux check arguments is directory |
| "find"    | "find"     | ?           | ?          | does not work with process csharp ??             |
| "open"    | "open"     | "open"      | "xdg-open" |                                                  |
| "print"   | "print"    | "lpr"       | "lpr".     |                                                  |
| "runas"   | "runas"    | "osascript" | ?          |                                                  |
 
## osascript on macOS:

* link : 

[see](https://hybridhacker.com/ask-for-sudo-password-in-graphical-mode-on-macos-x.html)

* command line :

```shell
osascript = "osascript -e "do shell script \"App.app/Contents/MacOS/App\" with administrator privileges""
```

* TextEdit example :

```shell
osascript -e "do shell script \"/System/Applications/TextEdit.app/Contents/MacOS/TextEdit\" with administrator privileges"
```

* TextEdit example with system :

```c++
system("osascript -e \"do shell script \\\"/System/Applications/TextEdit.app/Contents/MacOS/TextEdit\\\" with administrator privileges\"");
```
