cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled touch.c
        cp.c
        cp-hash.c
        dd.c
        df.c
        du.c
        install.c
        ln.c
        ls.c
        mkdir.c
        mkfifo.c
        mknod.c
        mv.c
        rm.c
        rmdir.c
        chgrp.c
        chmod.c
        chown.c
        cat1.c
        ../lib/argmatch.c
        ../lib/backupfile.c
        ../lib/backupfile.h
        ../lib/dirname.c
        ../lib/fileblocks.c
        ../lib/filemode.c
        ../lib/fnmatch.c
        ../lib/fnmatch.h
        ../lib/fsusage.c
        ../lib/fsusage.h
        ../lib/ftruncate.c
        ../lib/getversion.c
        ../lib/idcache.c
        ../lib/isdir.c
        ../lib/Makefile.in
        ../lib/makepath.c
        ../lib/mkdir.c
        ../lib/modechange.c
        ../lib/modechange.h
        ../lib/mountlist.c
        ../lib/mountlist.h
        ../lib/rename.c
        ../lib/savedir.c
        ../lib/stpcpy.c
        ../lib/strdup.c
        ../lib/stripslash.c
        ../lib/strstr.c
        ../lib/userspec.c
        ../lib/xstrdup.c
        ../lib/yesno.c)