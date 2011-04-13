#include "PolySaveManagerClass.h"
#include <nds/memory.h>
#include <nds/bios.h>

PolySaveManagerClass::PolySaveManagerClass()
{
}

PolySaveManagerErrorsEnum PolySaveManagerClass::Read(unsigned char* ApplicationID, void* Data, int Size)
{
	bool SRAMMappedToARM7;
	unsigned char c1;
	unsigned char c2;
	unsigned char c3;
	unsigned char c4;
	unsigned char c5;
	unsigned char c6;
	unsigned char c7;
	unsigned char c8;
	unsigned char c9;
	unsigned char c10;
	bool Finish;
	int i;
	int len;
	int chk;
	int j;

	if(Size > 65535)
	{
		return PolySaveErrorDataNotEnoughSpace;
	};
	SRAMMappedToARM7 = ((REG_EXMEMCNT & 0x80) != 0);
	sysSetCartOwner(BUS_OWNER_ARM9);
	swiDelay(10000);
	c1 = *((unsigned char*)(0x080000AC));
	c2 = *((unsigned char*)(0x080000AD));
	c3 = *((unsigned char*)(0x080000AE));
	c4 = *((unsigned char*)(0x080000AF));
	if((c1 == 0)&&(c2 == 0)&&(c3 == 0)&&(c4 == 0))
	{
		if(SRAMMappedToARM7)
		{
			sysSetCartOwner(BUS_OWNER_ARM7);
		};
		return PolySaveErrorNoCart;
	} else if((c1 == 255)&&(c2 == 255)&&(c3 == 255)&&(c4 == 255))
	{
		if(SRAMMappedToARM7)
		{
			sysSetCartOwner(BUS_OWNER_ARM7);
		};
		return PolySaveErrorNoCart;
	} else if((c1 != 80)||(c2 != 65)||(c3 != 83)||(c4 != 83))
	{
		if(SRAMMappedToARM7)
		{
			sysSetCartOwner(BUS_OWNER_ARM7);
		};
		return PolySaveErrorUnrecognizedCart;
	};
	c1 = *(SRAM + 0);
	c2 = *(SRAM + 1);
	c3 = *(SRAM + 2);
	c4 = *(SRAM + 3);
	c5 = *(SRAM + 4);
	c6 = *(SRAM + 5);
	c7 = *(SRAM + 6);
	c8 = *(SRAM + 7);
	if((c1 != 80)||(c2 != 111)||(c3 != 108)||(c4 != 121)||(c5 != 83)||(c6 != 97)||(c7 != 118)||(c8 != 101))
	{
		if(SRAMMappedToARM7)
		{
			sysSetCartOwner(BUS_OWNER_ARM7);
		};
		return PolySaveErrorDamagedHeader;
	};
	Finish = false;
	i = 8;
	while(!Finish)
	{
		c1 = *(SRAM + i);
		c2 = *(SRAM + i + 1);
		c3 = *(SRAM + i + 2);
		c4 = *(SRAM + i + 3);
		c5 = *(SRAM + i + 4);
		c6 = *(SRAM + i + 5);
		c7 = *(SRAM + i + 6);
		c8 = *(SRAM + i + 7);
		c9 = *(SRAM + i + 8);
		c10 = *(SRAM + i + 9);
		i = i + 10;
		len = ((int)c7) * 256 + ((int)c8);
		if(i + Size > 65535)
		{
			if(SRAMMappedToARM7)
			{
				sysSetCartOwner(BUS_OWNER_ARM7);
			};
			return PolySaveErrorDataNotEnoughSpace;
		};
		if((c1 == ApplicationID[0])&&(c2 == ApplicationID[1])&&(c3 == ApplicationID[2])&&(c4 == ApplicationID[3])&&(c5 == ApplicationID[4])&&(c6 == ApplicationID[5]))
		{
			if(len == Size)
			{
				chk = 0; 
				for(j = 0; j < len; j++)
				{
					*(((unsigned char*)(Data)) + j) = *(SRAM + i + j);
					chk = (chk + (*(SRAM + i + j))) & 0xFFFF;
				};
				if(SRAMMappedToARM7)
				{
					sysSetCartOwner(BUS_OWNER_ARM7);
				};
				if(chk != ((int)c9) * 256 + ((int)c10))
				{
					return PolySaveErrorDataInvalidChecksum;
				} else
				{
					return PolySaveErrorNone;
				};
				Finish = true;				
			};
		} else if((c1 == 0)&&(c2 == 0)&&(c3 == 0)&&(c4 == 0)&&(c5 == 0)&&(c6 == 0))
		{
			Finish = true;
		};
		i = i + len;
	};
	if(SRAMMappedToARM7)
	{
		sysSetCartOwner(BUS_OWNER_ARM7);
	};
	return PolySaveErrorDataDoesNotExist;
}

PolySaveManagerErrorsEnum PolySaveManagerClass::Write(unsigned char* ApplicationID, void* Data, int Size)
{
	bool SRAMMappedToARM7;
	unsigned char c1;
	unsigned char c2;
	unsigned char c3;
	unsigned char c4;
	unsigned char c5;
	unsigned char c6;
	unsigned char c7;
	unsigned char c8;
	unsigned char c9;
	unsigned char c10;
	bool Rebuild;
	bool Finish;
	int i;
	int len;
	int chk;
	int j;

	if(Size > 65535)
	{
		return PolySaveErrorDataNotEnoughSpace;
	};
	SRAMMappedToARM7 = ((REG_EXMEMCNT & 0x80) != 0);
	sysSetCartOwner(BUS_OWNER_ARM9);
	swiDelay(10000);
	c1 = *((unsigned char*)(0x080000AC));
	c2 = *((unsigned char*)(0x080000AD));
	c3 = *((unsigned char*)(0x080000AE));
	c4 = *((unsigned char*)(0x080000AF));
	if((c1 == 0)&&(c2 == 0)&&(c3 == 0)&&(c4 == 0))
	{
		if(SRAMMappedToARM7)
		{
			sysSetCartOwner(BUS_OWNER_ARM7);
		};
		return PolySaveErrorNoCart;
	} else if((c1 == 255)&&(c2 == 255)&&(c3 == 255)&&(c4 == 255))
	{
		if(SRAMMappedToARM7)
		{
			sysSetCartOwner(BUS_OWNER_ARM7);
		};
		return PolySaveErrorNoCart;
	} else if((c1 != 80)||(c2 != 65)||(c3 != 83)||(c4 != 83))
	{
		if(SRAMMappedToARM7)
		{
			sysSetCartOwner(BUS_OWNER_ARM7);
		};
		return PolySaveErrorUnrecognizedCart;
	};
	c1 = *(SRAM + 0);
	c2 = *(SRAM + 1);
	c3 = *(SRAM + 2);
	c4 = *(SRAM + 3);
	c5 = *(SRAM + 4);
	c6 = *(SRAM + 5);
	c7 = *(SRAM + 6);
	c8 = *(SRAM + 7);
	Rebuild = false;
	if((c1 != 80)||(c2 != 111)||(c3 != 108)||(c4 != 121)||(c5 != 83)||(c6 != 97)||(c7 != 118)||(c8 != 101))
	{
		*(SRAM + 0) = 80;
		*(SRAM + 1) = 111;
		*(SRAM + 2) = 108;
		*(SRAM + 3) = 121;
		*(SRAM + 4) = 83;
		*(SRAM + 5) = 97;
		*(SRAM + 6) = 118;
		*(SRAM + 7) = 101;
		Rebuild = true;
	};
	i = 8;
	if(!Rebuild)
	{
		Finish = false;
		while(!Finish)
		{
			c1 = *(SRAM + i);
			c2 = *(SRAM + i + 1);
			c3 = *(SRAM + i + 2);
			c4 = *(SRAM + i + 3);
			c5 = *(SRAM + i + 4);
			c6 = *(SRAM + i + 5);
			c7 = *(SRAM + i + 6);
			c8 = *(SRAM + i + 7);
			c9 = *(SRAM + i + 8);
			c10 = *(SRAM + i + 9);
			i = i + 10;
			len = ((int)c7) * 256 + ((int)c8);
			if(i + Size > 65535)
			{
				if(SRAMMappedToARM7)
				{
					sysSetCartOwner(BUS_OWNER_ARM7);
				};
				return PolySaveErrorDataNotEnoughSpace;
			};
			if((c1 == ApplicationID[0])&&(c2 == ApplicationID[1])&&(c3 == ApplicationID[2])&&(c4 == ApplicationID[3])&&(c5 == ApplicationID[4])&&(c6 == ApplicationID[5]))
			{
				if(len == Size)
				{
					i = i - 10;
					Finish = true;				
				} else
				{
					i = i + len;
				};
			} else if((c1 == 0)&&(c2 == 0)&&(c3 == 0)&&(c4 == 0)&&(c5 == 0)&&(c6 == 0))
			{
				i = i - 10;
				Rebuild = true;
				Finish = true;
			} else
			{
				i = i + len;
			};
		};
	};
	*(SRAM + i) = ApplicationID[0];
	*(SRAM + i + 1) = ApplicationID[1];
	*(SRAM + i + 2) = ApplicationID[2];
	*(SRAM + i + 3) = ApplicationID[3];
	*(SRAM + i + 4) = ApplicationID[4];
	*(SRAM + i + 5) = ApplicationID[5];
	*(SRAM + i + 6) = (Size >> 8) & 0xFF;
	*(SRAM + i + 7) = Size & 0xFF;
	chk = 0; 
	for(j = 0; j < Size; j++)
	{
		*(SRAM + i + 10 + j) = *(((unsigned char*)(Data)) + j);
		chk = (chk + (*(((unsigned char*)(Data)) + j))) & 0xFFFF;
	};
	*(SRAM + i + 8) = (chk >> 8);
	*(SRAM + i + 9) = (chk & 0xFF);
	if(Rebuild)
	{
		i = i + 10 + Size;
		*(SRAM + i) = 0;
		*(SRAM + i + 1) = 0;
		*(SRAM + i + 2) = 0;
		*(SRAM + i + 3) = 0;
		*(SRAM + i + 4) = 0;
		*(SRAM + i + 5) = 0;
		*(SRAM + i + 6) = 0;
		*(SRAM + i + 7) = 0;
		*(SRAM + i + 8) = 0;
		*(SRAM + i + 9) = 0;
	};
	if(SRAMMappedToARM7)
	{
		sysSetCartOwner(BUS_OWNER_ARM7);
	};
	return PolySaveErrorNone;
}

PolySaveManagerClass::~PolySaveManagerClass()
{
}
