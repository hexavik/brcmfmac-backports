/*
   BlueZ - Bluetooth protocol stack for Linux
   Copyright (C) 2014 Intel Corporation

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 2 as
   published by the Free Software Foundation;

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS.
   IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) AND AUTHOR(S) BE LIABLE FOR ANY
   CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES
   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

   ALL LIABILITY, INCLUDING LIABILITY FOR INFRINGEMENT OF ANY PATENTS,
   COPYRIGHTS, TRADEMARKS OR OTHER RIGHTS, RELATING TO USE OF THIS
   SOFTWARE IS DISCLAIMED.
*/
#if IS_ENABLED(CPTCFG_BT_SELFTEST)
#if LINUX_VERSION_IS_GEQ(3,1,0)
    && IS_MODULE(CPTCFG_BT)
#endif

/* When CPTCFG_BT_SELFTEST=y and the CPTCFG_BT=m, then the self testing
 * is run at module loading time.
 */
int bt_selftest(void);

#else

/* When CPTCFG_BT_SELFTEST=y and CPTCFG_BT=y, then the self testing
 * is run via late_initcall() to make sure that subsys_initcall() of
 * the Bluetooth subsystem and device_initcall() of the Crypto subsystem
 * do not clash.
 *
 * When CPTCFG_BT_SELFTEST=n, then this turns into an empty call that
 * has no impact.
 */
static inline int bt_selftest(void)
{
	return 0;
}

#endif
