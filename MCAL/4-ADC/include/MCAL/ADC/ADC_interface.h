/**
 * @file ADC_interface.h
 * @author Abdelrahman Kamal (abdelrahman.k212@gmail.com)
 * @brief functions prototype of ACD peripheral
 * @version 0.1
 * @date 2023-06-13
 */
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

/* ADC auto trigger options */
#define FREE_RUNNING            0b00000000
#define ANALOG_COMPARATOR       0b00100000
#define EXTI_INT0               0b01000000
#define TMR0_COMPARE_MATCH      0b01100000
#define TMR0_OVER_FLOW          0b10000000
#define TMR1_COMPARE_MATCH_B    0b10100000
#define TMR1_OVER_FLOW          0b11000000
#define TMR1_CAPTURE_EVENT      0b11100000

/* ADC channels options */
typedef enum
{
    ADC_SINGLE_ENDED_CH0,
    ADC_SINGLE_ENDED_CH1,
    ADC_SINGLE_ENDED_CH2,
    ADC_SINGLE_ENDED_CH3,
    ADC_SINGLE_ENDED_CH4,
    ADC_SINGLE_ENDED_CH5,
    ADC_SINGLE_ENDED_CH6,
    ADC_SINGLE_ENDED_CH7,

/* ADC_DIFF_PositiveChannelNumber_NegativeChannelNumber_Gain */
    ADC_DIFF_PCH0_NCH0_G10,
    ADC_DIFF_PCH1_NCH0_G10,

    ADC_DIFF_PCH0_NCH0_G200,
    ADC_DIFF_PCH1_NCH0_G200,

    ADC_DIFF_PCH2_NCH2_G10,
    ADC_DIFF_PCH3_NCH2_G10,

    ADC_DIFF_PCH2_NCH2_G200,
    ADC_DIFF_PCH3_NCH2_G200,
    ADC_DIFF_PCH0_NCH1_G1,
    ADC_DIFF_PCH1_NCH1_G1,
    ADC_DIFF_PCH2_NCH1_G1,
    ADC_DIFF_PCH3_NCH1_G1,
    ADC_DIFF_PCH4_NCH1_G1,
    ADC_DIFF_PCH5_NCH1_G1,
    ADC_DIFF_PCH6_NCH1_G1,
    ADC_DIFF_PCH7_NCH1_G1,
    ADC_DIFF_PCH0_NCH2_G1,
    ADC_DIFF_PCH1_NCH2_G1,
    ADC_DIFF_PCH2_NCH2_G1,
    ADC_DIFF_PCH3_NCH2_G1,
    ADC_DIFF_PCH4_NCH2_G1,
    ADC_DIFF_PCH5_NCH2_G1,

    ADC_SINGLE_ENDED_1220mV,
    ADC_SINGLE_ENDED_GND
}ADC_CHANNEL_t;

typedef struct
{
    uint8 ChainSize;
    ADC_CHANNEL_t* ChannelArray;

#if ADC_u8RESOLUTION == EIGHT_BITS
    uint8* ResultArray;
#elif ADC_u8RESOLUTION == TEN_BITS
    uint16* ResultArray;
#endif

    void (*ADC_pvfNotificationFunc)(void);
}ADC_CHAIN_t;

void ADC_vInit(void);
uint8 ADC_u8StartConversionSync(ADC_CHANNEL_t Copy_u8Channel, uint16* Copy_pu16Result);
uint8 ADC_u8StartConversionAsync(ADC_CHANNEL_t Copy_u8Channel, uint16* Copy_pu16Result, void(*Copy_pvfNotificationFunc)(void));
uint8 ADC_u8StartChainConversionAsync(ADC_CHAIN_t* Copy_strChain);

#endif /* ADC_INTERFACE_H_ */
