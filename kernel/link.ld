ENTRY(_start)

SECTIONS
{
	. = 0x1000;

	.text BLOCK(1K) : ALIGN(1K)
	{
		*(.text)
	}

	/* Read-only data. */
	.rodata BLOCK(1K) : ALIGN(1K)
	{
		*(.rodata)
	}

	/* Read-write data (initialized) */
	.data BLOCK(1K) : ALIGN(1K)
	{
		*(.data)
	}

	/* Read-write data (uninitialized) and stack */
	.bss BLOCK(1K) : ALIGN(1K)
	{
		*(COMMON)
		*(.bss)
	}
}

