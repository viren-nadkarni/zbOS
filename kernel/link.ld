ENTRY(start)
_start_ = 0x1000;

SECTIONS
{
	.text _start_ :
	{
        _code_ = .;
		*(.text)
		*(.rodata)
        . = ALIGN(4K);
	}

	.data :
	{
        _data_ = .;
		*(.data)
        . = ALIGN(4K);
	}

	.bss :
	{
        _bss_ = .;
		*(.bss)
        . = ALIGN(8K);
	}

    _end_ = .;
}

