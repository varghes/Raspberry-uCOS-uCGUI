#include "mylcd.h"
#include "stdlib.h"
#include "font.h" 
#include "usart.h"	 
#include "delay.h"	   
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//7寸 TFT液晶驱动	  
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2013/3/17
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved	
//********************************************************************************
//无
//////////////////////////////////////////////////////////////////////////////////	 
				 
//LCD的画笔颜色和背景色	   
u16 myPOINT_COLOR=0x00ff;	//画笔颜色
u16 myBACK_COLOR=0xFFFF;  //背景色 

//管理LCD重要参数
//默认为竖屏
_lcd_dev lcddev;
	
		   
//写寄存器函数
//regval:寄存器值
void LCD_WR_REG(u16 regval)
{ 
	myLCD->LCD_REG=regval;//写入要写的寄存器序号	 
}
//写LCD数据
//data:要写入的值
void LCD_WR_DATA(u16 data)
{										    	   
	myLCD->LCD_RAM=data;		 
}
//读LCD数据
//返回值:读到的值
u16 LCD_RD_DATA(void)
{										    	   
	return myLCD->LCD_RAM;		 
}					   
//写寄存器
//LCD_Reg:寄存器地址
//LCD_RegValue:要写入的数据
void LCD_WriteReg(u8 LCD_Reg, u16 LCD_RegValue)
{	
	myLCD->LCD_REG = LCD_Reg;		//写入要写的寄存器序号	 
	myLCD->LCD_RAM = LCD_RegValue;//写入数据	    		 
}	   
//读寄存器
//LCD_Reg:寄存器地址
//返回值:读到的数据
u16 LCD_ReadReg(u8 LCD_Reg)
{										   
	myLCD->LCD_REG = LCD_Reg;		//写入要写的寄存器序号	 
	return myLCD->LCD_RAM;
}   
//开始写GRAM
void LCD_WriteRAM_Prepare(void)
{
 	myLCD->LCD_REG=lcddev.wramcmd;	  
}	 
//LCD写GRAM
//RGB_Code:颜色值
void LCD_WriteRAM(u16 RGB_Code)
{							    
	myLCD->LCD_RAM = RGB_Code;//写十六位GRAM
}	 
//读取个某点的颜色值	 
//x,y:坐标
//返回值:此点的颜色
u16 LCD_ReadPoint(u16 x,u16 y)
{
 	u16 t=0;
 	LCD_SetCursor(x,y);	    
	while(t<0X1FFF)
	{	
		if(myLCD->LCD_REG&0x0001)break; 
		t++;		   
	}					   
	return myLCD->LCD_RAM; 	
}
//LCD背光设置
//pwm:背光等级,0~63.越大越亮.
void LCD_BackLightSet(u8 pwm)
{	
	lcddev.sysreg&=~0X003F;					//清除之前的设置
	lcddev.sysreg|=pwm&0X3F;				//设置新的值		
	LCD_WriteReg(LCD_PREF,lcddev.sysreg);	//写LCD_PREF寄存器	   	 	 
}
//扫描方向上,X的终点坐标.
void LCD_EndXSet(u16 x)
{													    		
	LCD_WriteReg(LCD_END_X,x);				//设置X终坐标  	 	 
}			 
//LCD开启显示
void LCD_DisplayOn(void)
{	
	LCD_WriteReg(LCD_PREF,lcddev.sysreg);	//恢复LCD_PREF寄存器	   	 
}	 
//LCD关闭显示
void LCD_DisplayOff(void)
{	   
	LCD_WriteReg(LCD_PREF,0);				//关闭TFT,相当于把背光关掉，无背光，无显示  	 
} 
//设置当前显示层
//layer:当前显示层 
void LCD_SetDisplayLayer(u16 layer)
{	 
	lcddev.sysreg&=~0X0E00;				   	//清除之前的设置
	lcddev.sysreg|=(layer&0X07)<<9;			//设置新的值
	LCD_WriteReg(LCD_PREF,lcddev.sysreg);	//写LCD_PREF寄存器	   	 	 
} 
//设置当前操作层
//layer:当前显示层 
void LCD_SetOperateLayer(u16 layer)
{	 
	lcddev.sysreg&=~0X7000;					//清除之前的设置
	lcddev.sysreg|=(layer&0X07)<<12;		//设置新的值
	LCD_WriteReg(LCD_PREF,lcddev.sysreg);	//写LCD_PREF寄存器	   	 	 
} 	     
//设置光标位置
//Xpos:横坐标
//Ypos:纵坐标
void LCD_SetCursor(u16 Xpos, u16 Ypos)
{	 
	LCD_WriteReg(lcddev.setycmd,Ypos);	//设置Y坐标 	 
	LCD_WriteReg(lcddev.setxcmd,Xpos);	//设置X坐标 	 
} 		 										 
//设置LCD的自动扫描方向
//注意:我们的驱动器,只支持左右扫描设置,不支持上下扫描设置   	   
void LCD_Scan_Dir(u8 dir)
{			   
    switch(dir)
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
	}
}   
//画点
//x,y:坐标
//POINT_COLOR:此点的颜色
void LCD_DrawPoint(u16 x,u16 y)
{
	LCD_SetCursor(x,y);		//设置光标位置 
	LCD_WriteRAM_Prepare();	//开始写入GRAM
	myLCD->LCD_RAM=myPOINT_COLOR; 
}
//快速画点
//x,y:坐标
//color:颜色
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color)
{	  		 		   
	myLCD->LCD_REG=lcddev.setycmd;
	myLCD->LCD_RAM=y; 
 	myLCD->LCD_REG=lcddev.setxcmd; 
	myLCD->LCD_RAM=x; 
	myLCD->LCD_REG=lcddev.wramcmd; 
	myLCD->LCD_RAM=color; 
}	
//设置LCD显示方向（7寸屏,不能简单的修改为横屏显示）
//dir:0,竖屏；1,横屏
void LCD_Display_Dir(u8 dir)
{
	 							    	  
}	 
//初始化lcd
//该初始化函数可以初始化各种ILI93XX液晶,但是其他函数是基于ILI9320的!!!
//在其他型号的驱动芯片上没有测试! 
void LCD_Init_driver(void)
{ 	
	u16 i;									  
	RCC->AHBENR|=1<<8;      //使能FSMC时钟	  
  	RCC->APB2ENR|=1<<3;     //使能PORTB时钟
	RCC->APB2ENR|=1<<5;     //使能PORTD时钟
	RCC->APB2ENR|=1<<6;     //使能PORTE时钟
 	RCC->APB2ENR|=1<<8;     //使能PORTG时钟	 
	GPIOB->CRL&=0XFFFFFFF0;	//PB0 推挽输出 复位引脚
	GPIOB->CRL|=0X00000003;	   
	//PORTD复用推挽输出 	
	GPIOD->CRH&=0X00FFF000;
	GPIOD->CRH|=0XBB000BBB; 
	GPIOD->CRL&=0XFF00FF00;
	GPIOD->CRL|=0X00BB00BB;   	 
	//PORTE复用推挽输出 	
	GPIOE->CRH&=0X00000000;
	GPIOE->CRH|=0XBBBBBBBB; 
	GPIOE->CRL&=0X0FFFFFFF;
	GPIOE->CRL|=0XB0000000;    	    	 											 
	//PORTG12复用推挽输出  	    	 											 
	GPIOG->CRH&=0XFFF0FFFF;
	GPIOG->CRH|=0X000B0000; 
	GPIOG->CRL&=0XFFFFFFF0;//PG0->RS
	GPIOG->CRL|=0X0000000B; 	  
	//寄存器清零
	//bank1有NE1~4,每一个有一个BCR+TCR，所以总共八个寄存器。
	//这里我们使用NE4 ，也就对应BTCR[6],[7]。				    
	FSMC_Bank1->BTCR[6]=0X00000000;
	FSMC_Bank1->BTCR[7]=0X00000000;
	FSMC_Bank1E->BWTR[6]=0X00000000;
	//操作BCR寄存器	使用异步模式
	FSMC_Bank1->BTCR[6]|=1<<12;		//存储器写使能
	FSMC_Bank1->BTCR[6]|=1<<14;		//读写使用不同的时序
	FSMC_Bank1->BTCR[6]|=1<<4; 		//存储器数据宽度为16bit 	    
	//操作BTR寄存器	
	//读时序控制寄存器 							    
	FSMC_Bank1->BTCR[7]|=0<<28;		//模式A 	 							  	 
	FSMC_Bank1->BTCR[7]|=0<<0; 		//地址建立时间（ADDSET）为1个HCLK 	 	 
	//因为液晶驱动IC的读数据的时候，速度不能太快 
	FSMC_Bank1->BTCR[7]|=3<<8;  	//数据保存时间为4+3个HCLK	 	 
	//写时序控制寄存器  
	FSMC_Bank1E->BWTR[6]|=0<<28; 	//模式A 	 							    
	FSMC_Bank1E->BWTR[6]|=0<<0;		//地址建立时间（ADDSET）为1个HCLK 
 	//2个HCLK（HCLK=72M）  	 
	FSMC_Bank1E->BWTR[6]|=1<<8; 	//数据保存时间为2个HCLK	
	//使能BANK1,区域4
	FSMC_Bank1->BTCR[6]|=1<<0;		//使能BANK1，区域4	 
  	LCD_RST=0;
	delay_ms(100);
	LCD_RST=1;	   
	while(i<0X1FFF) 
	{
		if(LCD_RD_DATA()&0x0001)break;//等待控制器准备好
		i++;
  	} 
  	lcddev.setxcmd=LCD_CUR_X;	//设置写X坐标指令
 	lcddev.setycmd=LCD_CUR_Y;	//设置写Y坐标指令
 	lcddev.wramcmd=LCD_PIXELS;	//设置写入GRAM的指令
 	lcddev.width=800;			//设置宽度
 	lcddev.height=480;			//设置高度
	LCD_Scan_Dir(L2R_U2D);		//设置默认扫描方向.	 
	LCD_SetDisplayLayer(0);	 	//显示层为0
	LCD_SetOperateLayer(0);		//操作层也为0
	LCD_EndXSet(799);			//x终点坐标为800
	LCD_BackLightSet(63);		//背光设置为最亮
	LCD_Clear(WHITE);			//清屏
}  
//清屏函数
//color:要清屏的填充色
void LCD_Clear(u16 color)
{
	u32 index=0;      
	u32 totalpoint=lcddev.width;
	totalpoint*=lcddev.height; 	//得到总点数
	LCD_SetCursor(0x00,0x0000);	//设置光标位置 
	LCD_WriteRAM_Prepare();     //开始写入GRAM	 	  
	for(index=0;index<totalpoint;index++)
	{
		myLCD->LCD_RAM=color;	   
	}
}  
//在指定区域内填充单个颜色
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
//color:要填充的颜色
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color)
{          
	u16 i,j;
	u16 xlen=0;
	xlen=ex-sx+1;	   
	for(i=sy;i<=ey;i++)
	{
	 	LCD_SetCursor(sx,i);      				//设置光标位置 
		LCD_WriteRAM_Prepare();     			//开始写入GRAM	  
		for(j=0;j<xlen;j++)myLCD->LCD_RAM=color;	//送入LCD	    
	}
}  
//在指定区域内填充指定颜色块			 
//(sx,sy),(ex,ey):填充矩形对角坐标,区域大小为:(ex-sx+1)*(ey-sy+1)   
//color:要填充的颜色
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color)
{  
	u16 height,width;
	u16 i,j;
	width=ex-sx+1; 		//得到填充的宽度
	height=ey-sy+1;		//高度
 	for(i=0;i<height;i++)
	{
 		LCD_SetCursor(sx,sy+i);   	//设置光标位置 
		LCD_WriteRAM_Prepare();     //开始写入GRAM
		for(j=0;j<width;j++)myLCD->LCD_RAM=color[i*height+j];//写入数据 
	}	  
}  
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
	u16 colortemp=myPOINT_COLOR;      			     
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
		        if(temp&0x80)myPOINT_COLOR=colortemp;
				else myPOINT_COLOR=myBACK_COLOR;
				LCD_DrawPoint(x,y);	
				temp<<=1;
				y++;
				if(x>=lcddev.width){myPOINT_COLOR=colortemp;return;}//超区域了
				if((y-y0)==size)
				{
					y=y0;
					x++;
					if(x>=lcddev.width){myPOINT_COLOR=colortemp;return;}//超区域了
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
				if(x>=lcddev.height){myPOINT_COLOR=colortemp;return;}//超区域了
				if((y-y0)==size)
				{
					y=y0;
					x++;
					if(x>=lcddev.width){myPOINT_COLOR=colortemp;return;}//超区域了
					break;
				}
			}  	 
	    }     
	}
	myPOINT_COLOR=colortemp;	    	   	 	  
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






























