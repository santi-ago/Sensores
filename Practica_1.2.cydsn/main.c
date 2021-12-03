/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
uint16 VALADC = 0;
uint16 Temp = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_Start();
    LCD_Start();
    Opamp_1_Start();
    Opamp_2_Start();
    Opamp_3_Start();
    
    
    for(;;)
    {
        /* Place your application code here. */
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        VALADC = ADC_GetResult16();
        if (VALADC < 909) VALADC = 909;
        if (VALADC > 2686) VALADC = 2686;
        Temp =  (uint32)(VALADC-909)*4000/1777;
        
        LCD_Position(0,0);
        LCD_PrintString("Temp: ");
        LCD_PrintNumber(Temp/100);
        LCD_PutChar('.');
        LCD_PrintNumber(Temp/100%10);
        LCD_PrintNumber(Temp%10);
        LCD_PutChar(LCD_CUSTOM_0);
        LCD_PutChar('C');
        
        LCD_Position(1,0);
        LCD_PrintString("ADC: ");
        LCD_PrintNumber(VALADC);
        
        LCD_Position(2,0);
        LCD_PrintString("n: 12 Res: 0.02");
        LCD_PutChar(LCD_CUSTOM_0);
        LCD_PutChar('C');
        
        LCD_Position(3,0);
        LCD_PrintString("Vref: 4.61V");
        
        CyDelay(500);
        LCD_ClearDisplay();
        
    }
}

/* [] END OF FILE */
