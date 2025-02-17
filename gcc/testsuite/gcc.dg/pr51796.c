/* PR bootstrap/51796 */
/* { dg-do compile } */
/* { dg-options "-Os -fno-omit-frame-pointer -fno-tree-dominator-opts -fno-tree-fre -fno-tree-pre" } */
/* { dg-require-effective-target gcc_internals } */

void stop (void);
typedef void (*entry_func) (void) __attribute__ ((noreturn));
extern entry_func entry_addr;
static void bsd_boot_entry (void)
{
  stop ();
}   
void bsd_boot (void)
{
  entry_addr = (entry_func) bsd_boot_entry;
  (*entry_addr) ();
}
