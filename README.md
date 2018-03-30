# 42_ls

This is my implementation of the famous terminal function "ls". <br />The following flags are available: <br />
## Flags
 -l  the following information is displayed for each file: file
     mode, number of links, owner name, group name, number of bytes in the file, abbreviated
     month, day-of-month file was last modified, hour file last modified, minute file last mod-
     ified, and the pathname.  In addition, for each directory whose contents are displayed,
     the total number of 512-byte blocks used by the files in the directory is displayed on a
     line by itself, immediately before the information for the files in the directory.  If the
     file or directory has extended attributes, the permissions field printed by the -l option
     is followed by a '@' character.  Otherwise, if the file or directory has extended security
     information (such as an access control list), the permissions field printed by the -l
     option is followed by a '+' character. <br />
 -R   Recursively list subdirectories encountered. <br />
 -a   Include directory entries whose names begin with a dot (.). <br />
 -r   Reverse the order of the sort to get reverse lexicographical order or the oldest entries
             first (or largest files last, if combined with sort by size <br />
 -t   Sort by time modified (most recently modified first) before sorting the operands by lexico-
             graphical order. <br />
