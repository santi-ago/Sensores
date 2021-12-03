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

uint16 VALADC;
uint16 Vref;
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_Start();
    LCD_Start();
    Opamp_1_Start();
    for(;;)
    {
        /* Place your application code here. */
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        VALADC = ADC_GetResult16();
        
        LCD_Position(0,0);
        LCD_PrintString("ADC = ");
        LCD_PrintNumber(VALADC);
        
        LCD_Position(1,0);
        LCD_PrintString("Vref+ = ");
        Vref = (4095*1000/VALADC) * 1.024;
        LCD_PrintNumber(Vref/1000);
        LCD_PutChar('.');
        LCD_PrintNumber(Vref/100%10);
        LCD_PrintNumber(Vref/10%10);
        LCD_PrintNumber(Vref%10);
        LCD_PrintString(" V");
        CyDelay(500);
        
        LCD_ClearDisplay();
        
    }
}

/* [] END OF FILE */
