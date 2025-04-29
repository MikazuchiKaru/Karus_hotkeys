**Karu's hotkeys**

Hello there, thank you for using my simple app. I hope it proves useful!


here's a basic manual:
First you have to download the exe file in the hotkey folder. Place it wherever inside an empty folder and create a text (.txt) file in the same place. In this file you can use a unique language created by your's truly. In the following text I will explain its syntax. (note: "{}" mean that in that place you write what you want based on the text inside)

For each macro you need a hotkey. You create those like this:
{modifier1}{modifier2}/{key}
--> modifiers
  ctrl = ^ (alt+94)
  shift = +
  alt = !
  win = %
--> keys
  mouse buttons
    left = LMB
    right = RMB
    middle = MMB
    additional button 1 = X1
    additional button 2 = X2
  keyboard buttons are exactly what the key says, you have to write letters in uppercase and F1 = F1 (uppercase 'f' + {num}), there may be some that aren't valid, in that case you will be notified, DO NOT USE SEMICOLON
  special buttons
    tabulator = TAB
    enter = ENTER
    backspace = BACKSPACE
    shift = SHIFT
    ctrl = CTRL
    alt = ALT
    capslock = CAPSLOCK
    esc = ESC
    pageup = PGUP
    pagedown = PGDN
    end = END
    home = HOME
    left = LEFT
    up = UP
    right = RIGHT
    down = DOWN
    insert = INS
    delete = DEL
    numlock = NUMLOCK
    scroll lock = SCROLLLOCK
    pause = PAUSE
    printscreen = PRINTSCREEN
    left windows = LWIN
    right windows = RWIN

  example:
  ^+/TAB = ctrl+shift+tab

  under each hotkey (what we were doing now) you write commands in this form
    {command}, {attribute1}, {attribute2}, {and so on...};
  it has to start with **4 spaces** (tabulator), then comes the command, then **comma and a space** and then however many attributes needed separated with **comma and a space**, it is **ended by semicolon**
  -->list of commands and their attributes
    exit, {0/1} = exits this program with either code 1 (error occured) or 0 (everything went well), it is on you to decide
    msgbox, {text}, {type} = displays a messagebox, you can write anything in text or type, but no commas or semicolons
    send, {text} = virtually types the entered text, can be a single character, again no commas or semicolons
    click, {left/right/middle} = clicks based on what you entered
    execute, {.exe file/HTML} = opens an app or a web page
    wait, {milliseconds} = macro will wait the set amount of milliseconds (1 second = 1000 milliseconds)
  
  you can enter multiple commands in a row
  
  example: (with ctrl + shift + TAB opens chrome and after one second displays messagebox)
  ^+/TAB
    execute, chrome.exe;
    wait, 1000;
    msgbox, chrome opened, custom alert;


additional notes:
Any lines without text and lines starting with '#' in the text file will be ignored (you can create notes for yourself with '#')
Don't try to intentionally break the code by not following these instructions, I am under no obligation to prevent each intentional user caused problem (like putting semicolon in a messagebox text message), it causes issues only for you so there is no reason to do so
