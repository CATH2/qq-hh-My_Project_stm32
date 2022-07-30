#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "stm32f10x.h"
#include "OLED_I2C.h"
#include "delay.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//ʹ��stm32f102zet6��oled-4pin��ʾ��
//����ȡģ��codetab.h �ļ���
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  

int main(void)
{
	unsigned char i;
	extern const unsigned char BMP1[];
	
	delay_init();
	I2C_Configuration();
	OLED_Init();
	
	while(1)
	{
		OLED_Fill(0xFF);//ȫ������
	  delay_ms(5000);
		OLED_Fill(0x00);//ȫ����
		delay_ms(5000);
		for(i=0;i<5;i++)
		{
			OLED_ShowCN(22+i*16,0,i);//������ʾ����
		}
		delay_ms(5000);
		OLED_ShowStr(0,3,"Hello world",1);//����6*8�ַ�
		OLED_ShowStr(0,4,"example",2);				//����8*16�ַ�
		delay_ms(5000);
		OLED_CLS();//����
		OLED_OFF();//����OLED����
    delay_ms(5000);
		OLED_ON();//����OLED���ߺ���
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//����BMPλͼ��ʾ
		delay_ms(5000);
	}
}