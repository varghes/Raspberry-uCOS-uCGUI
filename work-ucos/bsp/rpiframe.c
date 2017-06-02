#include "rpiframe.h"
#include "stdlib.h"
#include "font.h" 
//include "usart.h"	 
//#include "delay.h"	
#include "../uCGUI/core/LCD.h"   
#include "mailbox.h"
//////////////////////////////////////////////////////////////////////////////////	 

//////////////////////////////////////////////////////////////////////////////////	 
void put_pixel_RGB565(u32 x, u32 y, u16 color);
void put_pixel_RGB24(u32 x, u32 y, u8 red, u8 green, u8 blue);			 
//LCD的画笔颜色和背景色	   
u16 POINT_COLOR=0x0000;	//画笔颜色
u16 BACK_COLOR=0xFFFF;  //背景色 

_lcd_dev lcddev;
	
#define FNT_WIDTH	8
#define FNT_HEIGHT	16

// Framebuffer parameters
static u32 fb_address;
static u32 fb_size_bytes;
static u32 fb_x,fb_y,pitch,depth;

// Console parameters
//static u32 cons_x=1;
//static u32 cons_y=1;
static u32 console_init=0;

		  
// Read the pixel value
u16 LCD_ReadPoint(u16 x,u16 y)
{
	volatile u32 *ptr=0;
	u32 offset=0;
    u16 red,green,blue,pixel565;
	offset = (y * pitch) + (x * 3);
	ptr = (u32*)(fb_address + offset);
	blue=*((u8*)ptr);
	green =*((u8*)(ptr+1));
	red=*((u8*)(ptr+2)) ;
	
	 pixel565 = (red << 11) | (green << 5) | blue;
	return 	pixel565;
}

void put_pixel_RGB24(u32 x, u32 y, u8 red, u8 green, u8 blue)
{
	volatile u32 *ptr=0;
	u32 offset=0;

	offset = (y * pitch) + (x * 3);
	ptr = (u32*)(fb_address + offset);
	*((u8*)ptr) = blue;
	*((u8*)(ptr+1)) = green;
	*((u8*)(ptr+2)) = red ;
}

// No support 
void LCD_BackLightSet(u8 pwm)
{	
	lcddev.sysreg&=~0X003F;					
	lcddev.sysreg|=pwm&0X3F;			   	 	 
}

void LCD_DisplayOn(void)
{	
	;   	 
}	 
//No support
void LCD_DisplayOff(void)
{	   
 	 
} 
//设置当前显示层
//layer:当前显示层 
void LCD_SetDisplayLayer(u16 layer)
{	 
	lcddev.sysreg&=~0X0E00;				   	//清除之前的设置
	lcddev.sysreg|=(layer&0X07)<<9;			//设置新的值
	//LCD_WriteReg(LCD_PREF,lcddev.sysreg);	//写LCD_PREF寄存器	   	 	 
} 
//设置当前操作层
//layer:当前显示层 
void LCD_SetOperateLayer(u16 layer)
{	 
	lcddev.sysreg&=~0X7000;					//清除之前的设置
	lcddev.sysreg|=(layer&0X07)<<12;		//设置新的值
	//LCD_WriteReg(LCD_PREF,lcddev.sysreg);	//写LCD_PREF寄存器	   	 	 
} 	     
//设置光标位置
//Xpos:横坐标
//Ypos:纵坐标
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{	 
	//LCD_WriteReg(lcddev.setycmd,Ypos);	//设置Y坐标 	 
	//LCD_WriteReg(lcddev.setxcmd,Xpos);	//设置X坐标 	 
	lcddev.setycmd=Ypos;
	lcddev.setxcmd=Xpos;
} 		 										 
//设置LCD的自动扫描方向
//注意:我们的驱动器,只支持左右扫描设置,不支持上下扫描设置   	   
void LCD_Scan_Dir(u8 dir)
{			   
  /*  switch(dir)
	{
		case L2R_U2D:	//从左到右,从上到下
			LCD_WriteReg(LCD_MIRROR,1);	//写LCD_PREF寄存器
			break;
		case L2R_D2U:	//从左到右,从下到上
			LCD_WriteReg(LCD_MIRROR,3);	//写LCD_PREF寄存器
			break;
		case R2L_U2D:	//从右到左,从上到下
			LCD_WriteReg(LCD_MIRROR,0);	//写LCD_PREF寄存器
			break;
		case R2L_D2U:	//从右到左,从下到上
			LCD_WriteReg(LCD_MIRROR,2);	//写LCD_PREF寄存器
			break;	
		default:		//其他,默认从左到右,从上到下
			LCD_WriteReg(LCD_MIRROR,1);	//写LCD_PREF寄存器
			break;	 
	}*/
}   
//画点
//x,y:坐标
//POINT_COLOR:此点的颜色
void LCD_DrawPoint(u16 x,u16 y)
{
	/*LCD_SetCursor(x,y);		//设置光标位置 
	LCD_WriteRAM_Prepare();	//开始写入GRAM
	LCD->LCD_RAM=POINT_COLOR; */	
	
	u32 bits = (u32)POINT_COLOR;
    u32 blue = (bits & 0x001F);     // 5 bits blue
    u32 green = (bits & 0x07E0)>>5;    // 6 bits green
    u32 red = (bits & 0xF800)>>11;      // 5 bits red
    blue=blue<<3;
	green = green<<2;
	red = red<<3 ;
    put_pixel_RGB24(x, y, red , green,blue  );
}
//快速画点
//x,y:坐标
//color:颜色
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color)
{	  		 		   
	/*LCD->LCD_REG=lcddev.setycmd;
	LCD->LCD_RAM=y; 
 	LCD->LCD_REG=lcddev.setxcmd; 
	LCD->LCD_RAM=x; 
	LCD->LCD_REG=lcddev.wramcmd; 
	LCD->LCD_RAM=color; */
}	
//设置LCD显示方向（7寸屏,不能简单的修改为横屏显示）
//dir:0,竖屏；1,横屏
void LCD_Display_Dir(u8 dir)
{
	 ;							    	  
}	 
//初始化lcd
//该初始化函数可以初始化各种ILI93XX液晶,但是其他函数是基于ILI9320的!!!
//在其他型号的驱动芯片上没有测试! 
void LCD_Init_drive(void)
{ 	
	u32 retval=0;
    volatile unsigned int mb[100] __attribute__ ((aligned(16)));

	depth = 24;
	//
	// Get physical size
	//
    mb[0] = 8 * 4;		// Buffer size
    mb[1] = 0;			// Request
    mb[2] = 0x00040003;	// Tag id - Get physical width/height
    mb[3] = 2*4;		// Buffer size
    mb[4] = 0;			// Request/Response indicator (MSB 0 for request)
    mb[5] = 0;			// Width
    mb[6] = 0;			// Height
    mb[7] = 0;			// End tag

  //  klogBin("Get physical size - Request:", (uint8_t*)mb, mb[0]+4);

    MailboxWrite((u32)(mb+0x40000000), 8);

    if(((retval = MailboxRead(8)) == 0) || (mb[1] != 0x80000000)){
	//	klogStr("Get physical tag failed");
		return ;
	}
    
   // klogBin("Get physical size - Response:", (uint8_t*)mb, mb[0]+4);

    fb_x = mb[5];
    fb_y = mb[6];
 //   klogInt("Screen width:", fb_x);
 //   klogInt("Screen height:", fb_y);
//_x=800;//Screen resolbbut jjdddd
//_y= 600;

    u32 mb_pos=1;

    mb[mb_pos++] = 0;			// Request indicator
    mb[mb_pos++] = 0x00048003;	// Tag - Set physical width/height
    mb[mb_pos++] = 2*4;			// Value buffer length - 2 x sizeof(u32)
    mb[mb_pos++] = 2*4;			// Request indicator + value buffer length
    mb[mb_pos++] = fb_x;		// Width
    mb[mb_pos++] = fb_y;		// Height
    mb[mb_pos++] = 0x00048004;	// Tag - Set virtual width/height
	mb[mb_pos++] = 2*4;			// Value buffer length - 2 x sizeof(u32)
	mb[mb_pos++] = 2*4;			// Request indicator + value buffer length
	mb[mb_pos++] = fb_x;		// Width
	mb[mb_pos++] = fb_y;		// Height
	mb[mb_pos++] = 0x00048005;	// Tag - Set depth
	mb[mb_pos++] = 1*4;			// Value buffer length - 2 x sizeof(u32)
	mb[mb_pos++] = 1*4;			// Request indicator + value buffer length
	mb[mb_pos++] = depth;		// Depth
	mb[mb_pos++] = 0x00040001;	// Tag - Allocate buffer
	mb[mb_pos++] = 2*4;			// Value buffer length - 2 x sizeof(u32)
	mb[mb_pos++] = 2*4;			// Request indicator + value buffer length
	mb[mb_pos++] = 16;			// Alignment
	mb[mb_pos++] = 0;			// Place holder for response value
	mb[mb_pos++] = 0;			// End tag
	mb[0] = mb_pos*4;			// Size of the whole buffer

//	klogBin("Setup - Request:", (uint8_t*)mb, mb[0]+4);

	MailboxWrite((u32)(mb+0x40000000), 8);

	if(((retval = MailboxRead(8)) == 0) || (mb[1] != 0x80000000)){
	//	klogStr("Set physical tag failed");
		return ;
	}

//	klogBin("Setup - Response:", (uint8_t*)mb, mb[0]+4);

	mb_pos = 2;
	unsigned int val_buff_len=0;
	while(mb[mb_pos] != 0){
		switch(mb[mb_pos++])
		{
			case 0x00048003:
				val_buff_len = mb[mb_pos++];
				mb_pos+= (val_buff_len/4)+1;
				break;
			case 0x00048004:
				val_buff_len = mb[mb_pos++];
				mb_pos+= (val_buff_len/4)+1;
				break;
			case 0x00048005:
				val_buff_len = mb[mb_pos++];
				mb_pos+= (val_buff_len/4)+1;
				break;
			case 0x00040001:
				val_buff_len = mb[mb_pos++];
				mb_pos++;
				fb_address = mb[mb_pos++];
				fb_size_bytes = mb[mb_pos++];
				break;
		}
	}

	//
	// Get pitch
	//
	mb[0] = 8 * 4;		// Buffer size
	mb[1] = 0;			// Request
	mb[2] = 0x00040008;	// Tag id - Get pitch
	mb[3] = 4;			// Buffer size
	mb[4] = 0;			// Request length
	mb[5] = 0;			// Pitch
	mb[6] = 0;			// End tag
	mb[7] = 0;

//	klogBin("Get pitch - Request:", (uint8_t*)mb, mb[0]+4);

	MailboxWrite((u32)(mb+0x40000000), 8);

	if(((retval = MailboxRead(8)) == 0) || (mb[1] != 0x80000000)){
	//	klogStr("Get pitch tag failed");
		return ;
	}

//	klogBin("Get pitch - Response:", (uint8_t*)mb, mb[0]+4);

	console_init = 1;	// Flag to indicate that console is initialised
	pitch = mb[5];

//	klogBin("Framebuffer address: 0x", (uint8_t*)&fb_address, sizeof(fb_address));
//	klogInt("Framebuffer size:", fb_size_bytes);
//	klogInt("Pitch:", pitch);

	fb_x--;
	fb_y--;

	//display_logo();

//	console_write("Framebuffer initialised!\n");
//	console_write("Well done\r\n");
//	console_write("This deserves a beer");
	
	lcddev.setxcmd=LCD_CUR_X;	//设置写X坐标指令
 	lcddev.setycmd=LCD_CUR_Y;	//设置写Y坐标指令
 	lcddev.wramcmd=LCD_PIXELS;	//设置写入GRAM的指令
 	lcddev.width=1024;			//设置宽度
 	lcddev.height=600;			//设置高度
	LCD_Scan_Dir(L2R_U2D);		//设置默认扫描方向.	 
	LCD_SetDisplayLayer(0);	 	//显示层为0
	LCD_SetOperateLayer(0);		//操作层也为0
	//LCD_EndXSet(799);			//x终点坐标为800
	LCD_BackLightSet(63);		//背光设置为最亮
	//LCD_Clear(WHITE);			//清屏
	POINT_COLOR=0x007E0;     // green
    LCD_DrawLine(10, 10 , 500, 500);
	/*LCD_DrawRectangle(0,0, 400, 400);
	POINT_COLOR=0xF800      ;  // red
	Draw_Circle(200 ,200,50);
	POINT_COLOR=0x001F;   
	LCD_ShowString(200,200,60,30,12,"varghese");
	//LCD_ShowString(200,200,240,12,160,"Varghese");
	LCD_ShowxNum(300,300,50000,6,12,0);
	LCD_ShowNum(400,400,99999,6,12);
	LCD_Fill(300,300,500,400,0xFFE0);// yellow */
}  
//清屏函数
//color:要清屏的填充色
void LCD_Clear(u16 color)
{
	u32 index=0;    
    u32 i,j;	
	u32 totalpoint=lcddev.width;
	totalpoint*=lcddev.height; 	//得到总点数
	for(j=0;j<lcddev.height;j++)
	for(i=0;i<lcddev.width;i++)
		LCD_DrawPoint(i,j);
		
}  
//在指定区域内填充单个颜色
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
//color:要填充的颜色
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color)
{          
	
	u16 i,j;
	u16 xlen=0;
	xlen=ex-sx+1;	
	POINT_COLOR = color;	
	for(i=sy;i<=ey;i++)
	{	  
		for(j=sx;j<ex;j++)
			LCD_DrawPoint(j,i);
	}
}  



//在指定区域内填充指定颜色块			 
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
//color:要填充的颜色
/*void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color)
{  
	u16 height,width;
	u16 i,j;
	width=ex-sx+1; 		//得到填充的宽度
	height=ey-sy+1;		//高度
 	for(i=0;i<height;i++)
	{
 		LCD_SetCursor(sx,sy+i);   	//设置光标位置 
		LCD_WriteRAM_Prepare();     //开始写入GRAM
		for(j=0;j<width;j++)LCD->LCD_RAM=color[i*height+j];//写入数据 
	}	  
}  */
//画线
//x1,y1:起点坐标
//x2,y2:终点坐标  
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2)
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //设置单步方向 
	else if(delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//画线输出 
	{  
		LCD_DrawPoint(uRow,uCol);//画点 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
	
	 
}    
//画矩形	  
//(x1,y1),(x2,y2):矩形的对角坐标
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2)
{
	LCD_DrawLine(x1,y1,x2,y1);
	LCD_DrawLine(x1,y1,x1,y2);
	LCD_DrawLine(x1,y2,x2,y2);
	LCD_DrawLine(x2,y1,x2,y2);
}
//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void Draw_Circle(u16 x0,u16 y0,u8 r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPoint(x0+a,y0-b);             //5
 		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-a,y0+b);             //1       
 		LCD_DrawPoint(x0-b,y0+a);             
		LCD_DrawPoint(x0-a,y0-b);             //2             
  		LCD_DrawPoint(x0-b,y0-a);             //7     	         
		a++;
		//使用Bresenham算法画圆     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
} 									  
//在指定位置显示一个字符
//x,y:起始坐标
//num:要显示的字符:" "--->"~"
//size:字体大小 12/16
//mode:叠加方式(1)还是非叠加方式(0)
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode)
{  							  
    u8 temp,t1,t;
	u16 y0=y;
	u16 colortemp=POINT_COLOR;      			     
	//设置窗口		   
	num=num-' ';//得到偏移后的值
	if(!mode) //非叠加方式
	{
	    for(t=0;t<size;t++)
	    {   
			if(size==12)temp=asc2_1206[num][t];  //调用1206字体
			else temp=asc2_1608[num][t];		 //调用1608字体 	                          
	        for(t1=0;t1<8;t1++)
			{			    
		        if(temp&0x80)POINT_COLOR=colortemp;
				else POINT_COLOR=BACK_COLOR;
				LCD_DrawPoint(x,y);	
				temp<<=1;
				y++;
				if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//超区域了
				if((y-y0)==size)
				{
					y=y0;
					x++;
					if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//超区域了
					break;
				}
			}  	 
	    }    
	}else//叠加方式
	{
	    for(t=0;t<size;t++)
	    {   
			if(size==12)temp=asc2_1206[num][t];  //调用1206字体
			else temp=asc2_1608[num][t];		 //调用1608字体 	                          
	        for(t1=0;t1<8;t1++)
			{			    
		        if(temp&0x80)LCD_DrawPoint(x,y); 
				temp<<=1;
				y++;
				if(x>=lcddev.height){POINT_COLOR=colortemp;return;}//超区域了
				if((y-y0)==size)
				{
					y=y0;
					x++;
					if(x>=lcddev.width){POINT_COLOR=colortemp;return;}//超区域了
					break;
				}
			}  	 
	    }     
	}
	POINT_COLOR=colortemp;	    	   	 	  
}   
//m^n函数
//返回值:m^n次方.
u32 LCD_Pow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}			 
//显示数字,高位为0,则不显示
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//color:颜色 
//num:数值(0~4294967295);	 
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,' ',size,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,0); 
	}
} 
//显示数字,高位为0,还是显示
//x,y:起点坐标
//num:数值(0~999999999);	 
//len:长度(即要显示的位数)
//size:字体大小
//mode:
//[7]:0,不填充;1,填充0.
//[6:1]:保留
//[0]:0,非叠加显示;1,叠加显示.
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode)
{  
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)LCD_ShowChar(x+(size/2)*t,y,'0',size,mode&0X01);  
				else LCD_ShowChar(x+(size/2)*t,y,' ',size,mode&0X01);  
 				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01); 
	}
} 
//显示字符串
//x,y:起点坐标
//width,height:区域大小  
//size:字体大小
//*p:字符串起始地址		  
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p)
{         
	u8 x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//退出
        LCD_ShowChar(x,y,*p,size,0);
        x+=size/2;
        p++;
    }  
}

void ili9320_SetPixelIndex(u16 x, u16 y,u16 PixelIndex)
{
	
	POINT_COLOR = PixelIndex;
	LCD_DrawPoint(x, y);
}

u16 ili9320_GetPixelIndex(u16 x, u16 y)
{
	return LCD_ReadPoint(x, y);
}






























