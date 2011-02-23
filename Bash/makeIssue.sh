#!/bin/bash
echo -e '\e[H\e[2J' > issue
echo -e '       \e[0m,\e[0m                                                       OS: \\s \\m \\r' >> issue
echo -e '      \e[1;36m/#\\\\\e[0m      ____           _   _                          Time: \e[32m\\t ' >> issue
echo -e '     \e[1;36m,###\\\\\e[0m    / ___|__ _ _ __| |_| |__   __ _  __ _  ___     Date:\e[30m|\e[32m\\d' >> issue
echo -e '    \e[1;36m/#####\\\\\e[0m  | |   / _` | \x27__| __| \x27_ \\\\ / _` |/ _` |/ _ \\\\ Console: \e[31m\\l' >> issue
echo -e '   \e[1;36m/##\e[0;36m,-,##\\\\\e[0m | |__| (_| | |  | |_| | | | (_| | (_| |  __/   Users: \e[31m\\u' >> issue
echo -e '  \e[0;36m/##(   )##\\\\\e[0m \\\\____\\\\__,_|_|   \\\\__|_| |_|\\\\__,_|\\\\__, |\\\\___| ' >> issue 
echo -e ' \e[0;36m/#.--   --.#\\\\\e[0m                                |___/     ' >> issue
echo -e '\e[0;36m/`           `\\\\\e[0m    ' >> issue
echo -e '                Interest is a terrible thing to waste.' >> issue
echo -e '                                                   --Roger Schank' >> issue

