//#define DYN76_DEBUG
//#define DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
        {   /* Found the entry! */
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - orphan _close(%d)\n", fk->handle);
#endif
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - orphan _close result: %d\n", i);
#endif
            {
                i = errno;
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - orphan _close errno: %d\n", i);
#endif                
                i = -1 * i;
            }
            else 
            {
    int    res;                 /* I/O integer results */
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
        LOGMSG("DF18: CFILE - _close(%d)\n", handle);
        res = _close (handle);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _close result: %d\n", res);
#endif
        R15 = res;
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _commit(%d)\n", handle);
        res =  _commit (handle);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _commit result: %d\n", res);
#endif
#else /* ifdef __MSVC__ */

#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - fsync(%d)\n", handle);
#endif
        res = fsync (handle);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - fsync result: %d \n", res);
#endif
#endif /* ifdef __MSVC__ */
        if (res != 0)
        {
            res = errno;
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - fsync/_commit errno: %d \n", res);
#endif            
            R15 = -1 * res;
        }
        else
        {    
            R15 = res;
        }
        LOGMSG("DF18: CFILE - seek\n");
        get_reg(R3,3);  /* offset in bytes */
        get_reg(R4,4);  /* origin of the seek */
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _lseek(%d, %d, %d)\n", handle, (long)R3, (int)R4);
#endif
        res = _lseek (handle, (long)R3, (int)R4);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _lseek result: %d\n", res);
#endif        
        if (res == -1)
            res = errno;
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - _lseek errno: %d\n", res);
#endif            
            R15 = -1 * res;
        }
        else
        {    
            R15 = res;
#ifdef DYN76_DEBUG_FKEEPER
                    (&(rfk->oldname [rfk->data]), 
        LOGMSG("DF18: CFILE - rename\n");
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - rename(from='%s',to='%s')\n", 
                rfk->oldname, rfk->filename);
#endif
        res = rename (rfk->oldname, rfk->filename);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - rename result: %d\n", res);
#endif
        if (res != 0)
        {
            res = errno;
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - rename errno: %d\n", res);
#endif            
            R15 = -1 * res;
        }
        else
        {
            R15 = res;
        }
        LOGMSG("DF18: CFILE - unlink\n");
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _unkink('%s')\n", rfk->filename);
#endif  
        res = _unlink (rfk->filename);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _unlink result: %d\n", res);
#endif
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - remove('%s')\n", rfk->filename);
        res = remove (rfk->filename);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - remove result: %d\n", res);
#endif
#endif
        if (res != 0)
        {
            res = errno;
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - remove/_unlink errno: %d\n", res);
#endif            
            R15 = -1 * res;
        }
        else
        {
            R15 = res;
        }
        LOGMSG("DF18: CFILE - open\n");
        {
        }
        LOGMSG("DF18: CFILE - _open('%s', 0x%X, 0%o)\n", rfk->filename, i, R4);
        res = _open (rfk->filename, i, (mode_t)R4);
#ifdef DYN76_DEBUG
        LOGMSG("DF18: CFILE - _open result: %d\n", res);
#endif        
        if (res != -1) 
            rfk->handle = res;  /* Save the host handle */
#ifdef DYN76_DEBUG_FKEEPER
#ifdef DYN76_DEBUG_FKEEPER
            LOGMSG("DF18: CFILE - opened guest file descriptor %d, host handle: %d\n", 
                    rfk->id, rfk->handle);

            res = errno;
#ifdef DYN76_DEBUG
            LOGMSG("DF18: CFILE - _open errno: %X\n", res);
#endif
            R15 = -1 * res;
    {
        LOGMSG("DF18: CFILE - orphan close: '%s'\n", rfk->filename);
        LOGMSG("DF18: CFILE - read\n");
        LOGMSG("DF18: CFILE - write\n");
            LOGMSG("DF18: CFILE - _write(%d, rfk->filename, %d)\n", handle, i);
            res = _write (handle, rfk->filename, (size_t)i);
            LOGMSG("DF18: CFILE - _write result: %d\n", res);
            if (res < 0)
                io_error = errno;
                LOGMSG("DF18: CFILE - write errno: %d\n", io_error);
            /* Not an error, so 'res' is the number of bytes actually written */
            R2 += res;
            R4 -= res;
            R15 += res;
#ifdef DYN76_DEBUG_FKEEPER