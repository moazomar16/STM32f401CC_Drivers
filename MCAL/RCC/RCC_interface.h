/*
 *  Created by Moaz Omar
 *  Date: 2/15/2023
 *  Title: Embedded Software Intern @ ITI
 *  GitHub: https://github.com/moazomar16
 */



#ifndef STM32_RCC_INTERFACE_H
#define STM32_RCC_INTERFACE_H

#include "Libraries/Std_Types.h"



/**********************************************************
 *
 *          Clock Types
 *              options[2]:
 *                       1.HSI
 *                       2.HSE
 *                       3.HSE_bypass
 *                       4.PLL
 *                       5.PLLI2S
 *
 **********************************************************/
#define CLOCK_HSI           0x80000081
#define CLOCK_HSE           0x80010000
#define CLOCK_HSE_BYPASS    0x80050000
#define CLOCK_PLL           0x81000000
#define CLOCK_PLLI2S        0x84000000

/**********************************************************
 *
 *      Clock Security System
 *          options[2]:
 *                 1.Enable
 *                 2.Disable
 *
 **********************************************************/
#define CLOCK_SECURITY_SYSTEM_ENABLE        0x80080000
#define CLOCK_SECURITY_SYSTEM_DISABLE       0x80000000

/**********************************************************
 *
 *       Peripheral Clock For AHB1 Bus
 *          options[10]
 *                  1.GPIOA
 *                  2.GPIOB
 *                  3.GPIOC
 *                  4.GPIOD
 *                  5.GPIOE
 *                  6.GPIOH
 *                  7.CRC
 *                  8.DMA1
 *                  9.DMA2
 *                  10.All
 *
 **********************************************************/
#define BUS_AHB1_GPIOA                   0x40000001
#define BUS_AHB1_GPIOB                   0x40000002
#define BUS_AHB1_GPIOC                   0x40000004
#define BUS_AHB1_GPIOD                   0x40000008
#define BUS_AHB1_GPIOE                   0x40000010
#define BUS_AHB1_GPIOH                   0x40000080
#define BUS_AHB1_CRC                     0x40001000
#define BUS_AHB1_DMA1                    0x40200000
#define BUS_AHB1_DMA2                    0x40400000
#define BUS_AHB1_ALL                     0x4060109F

/**********************************************************
 *
 *       Peripheral Clock For AHB2 Bus
 *          options[1]
 *                  1.OTGFS
 *
 **********************************************************/
#define BUS_AHB2_OTGFS            0x80000080

/**********************************************************
 *
 *       Peripheral Clock For APB1 Bus
 *          options[12]
 *                  01.TIM2
 *                  02.TIM3
 *                  03.TIM4
 *                  04.TIM5
 *                  05.WWDG
 *                  06.SPI2
 *                  07.SPI3
 *                  08.USART2
 *                  09.I2C1
 *                  10.I2C2
 *                  11.I2C3
 *                  12.PWR
 *
 **********************************************************/
#define BUS_APB1_TIM2                   0x20000001
#define BUS_APB1_TIM3                   0x20000002
#define BUS_APB1_TIM4                   0x20000004
#define BUS_APB1_TIM5                   0x20000008
#define BUS_APB1_WWDG                   0x20000800
#define BUS_APB1_SPI2                   0x20004000
#define BUS_APB1_SPI3                   0x20008000
#define BUS_APB1_USART2                 0x20020000
#define BUS_APB1_I2C1                   0x20200000
#define BUS_APB1_I2C2                   0x20400000
#define BUS_APB1_I2C3                   0x20800000
#define BUS_APB1_PWR                    0x30000000
#define RCC_APB1_ALL				    0X30E2C80F

/**********************************************************
 *
 *       Peripheral Clock For APB2 Bus
 *          options[11]
 *                  01.TIM1
 *                  02.USART1
 *                  03.USART6
 *                  04.ADC1
 *                  05.SDIO
 *                  06.SPI1
 *                  07.SPI4
 *                  08.SYSCFG
 *                  09.TIM9
 *                  10.TIM10
 *                  11.TIM11
 *
 **********************************************************/
#define BUS_APB2_TIM1                   0x90000001
#define BUS_APB2_USART1                 0x90000010
#define BUS_APB2_USART6                 0x90000020
#define BUS_APB2_ADC1                   0x90000100
#define BUS_APB2_SDIO                   0x90000800
#define BUS_APB2_SPI1                   0x90001000
#define BUS_APB2_SPI4                   0x90002000
#define BUS_APB2_SYSCFG                 0x90004000
#define BUS_APB2_TIM9                   0x90010000
#define BUS_APB2_TIM10                  0x90020000
#define BUS_APB2_TIM11                  0x90040000
#define BUS_APB2_ALL                    0x90077931

/**********************************************************
 *
 *      PLL Configuration
 *          PLLQ[14]        2<=PLLQ<=15
 *              01.PLLQ=2
 *              02.PLLQ=3
 *              03.PLLQ=4
 *              04.PLLQ=5
 *              05.PLLQ=6
 *              06.PLLQ=7
 *              07.PLLQ=8
 *              08.PLLQ=9
 *              09.PLLQ=10
 *              10.PLLQ=11
 *              11.PLLQ=12
 *              12.PLLQ=13
 *              13.PLLQ=14
 *              14.PLLQ=15
 *          PLLSRC[2]
 *              1.HSI
 *              1 HES
 *          PLLP[2]
 *              1.PLLP = 2
 *              2.PLLP = 4
 *              3.PLLP = 6
 *              4.PLLP = 8
 *          PLLN[X] with 192 ≤PLLN ≤432
 *
 *          PLLM with 2 ≤PLLM ≤63
 *
 *
 *
 *
 **********************************************************/
#define PLLQ_DIV_BY_2                0xA1000000
#define PLLQ_DIV_BY_3                0xA2000000
#define PLLQ_DIV_BY_4                0xA3000000
#define PLLQ_DIV_BY_5                0xA4000000
#define PLLQ_DIV_BY_6                0xA5000000
#define PLLQ_DIV_BY_7                0xA6000000
#define PLLQ_DIV_BY_8                0xA7000000
#define PLLQ_DIV_BY_9                0xA8000000
#define PLLQ_DIV_BY_10               0xA9000000
#define PLLQ_DIV_BY_11               0xAA000000
#define PLLQ_DIV_BY_12               0xAB000000
#define PLLQ_DIV_BY_13               0xAC000000
#define PLLQ_DIV_BY_14               0xAD000000
#define PLLQ_DIV_BY_15               0xAE000000

#define PLLSRC_HSI                   0xA0000000
#define PLLSRC_HSE                   0xA0400000

#define PLLP_DIV_BY_2                0xA0000000
#define PLLP_DIV_BY_4                0xA0010000
#define PLLP_DIV_BY_6                0xA0020000
#define PLLP_DIV_BY_8                0xA0030000

#define PLLN_DIV_BY_192              0xA000C000
#define PLLN_DIV_BY_193              0xA000C100
#define PLLN_DIV_BY_194              0xA000C200
#define PLLN_DIV_BY_195              0xA000C300
#define PLLN_DIV_BY_196              0xA000C400
#define PLLN_DIV_BY_197              0xA000C500
#define PLLN_DIV_BY_198              0xA000C600
#define PLLN_DIV_BY_199              0xA000C700
#define PLLN_DIV_BY_200              0xA000C800
#define PLLN_DIV_BY_201              0xA000C900
#define PLLN_DIV_BY_202              0xA000CA00
#define PLLN_DIV_BY_203              0xA000CB00
#define PLLN_DIV_BY_204              0xA000CC00
#define PLLN_DIV_BY_205              0xA000CD00
#define PLLN_DIV_BY_206              0xA000CE00
#define PLLN_DIV_BY_207              0xA000CF00
#define PLLN_DIV_BY_208              0xA000D000
#define PLLN_DIV_BY_209              0xA000D100
#define PLLN_DIV_BY_210              0xA000D200
#define PLLN_DIV_BY_211              0xA000D300
#define PLLN_DIV_BY_212              0xA000D400
#define PLLN_DIV_BY_213              0xA000D500
#define PLLN_DIV_BY_214              0xA000D600
#define PLLN_DIV_BY_215              0xA000D700
#define PLLN_DIV_BY_216              0xA000D800
#define PLLN_DIV_BY_217              0xA000D900
#define PLLN_DIV_BY_218              0xA000DA00
#define PLLN_DIV_BY_219              0xA000DB00
#define PLLN_DIV_BY_220              0xA000DC00
#define PLLN_DIV_BY_221              0xA000DD00
#define PLLN_DIV_BY_222              0xA000DE00
#define PLLN_DIV_BY_223              0xA000DF00
#define PLLN_DIV_BY_224              0xA000E000
#define PLLN_DIV_BY_225              0xA000E100
#define PLLN_DIV_BY_226              0xA000E200
#define PLLN_DIV_BY_227              0xA000E300
#define PLLN_DIV_BY_228              0xA000E400
#define PLLN_DIV_BY_229              0xA000E500
#define PLLN_DIV_BY_230              0xA000E600
#define PLLN_DIV_BY_231              0xA000E700
#define PLLN_DIV_BY_232              0xA000E800
#define PLLN_DIV_BY_233              0xA000E900
#define PLLN_DIV_BY_234              0xA000EA00
#define PLLN_DIV_BY_235              0xA000EB00
#define PLLN_DIV_BY_236              0xA000EC00
#define PLLN_DIV_BY_237              0xA000ED00
#define PLLN_DIV_BY_238              0xA000EE00
#define PLLN_DIV_BY_239              0xA000EF00
#define PLLN_DIV_BY_240              0xA000F000
#define PLLN_DIV_BY_241              0xA000F100
#define PLLN_DIV_BY_242              0xA000F200
#define PLLN_DIV_BY_243              0xA000F300
#define PLLN_DIV_BY_244              0xA000F400
#define PLLN_DIV_BY_245              0xA000F500
#define PLLN_DIV_BY_246              0xA000F600
#define PLLN_DIV_BY_247              0xA000F700
#define PLLN_DIV_BY_248              0xA000F800
#define PLLN_DIV_BY_249              0xA000F900
#define PLLN_DIV_BY_250              0xA000FA00
#define PLLN_DIV_BY_251              0xA000FB00
#define PLLN_DIV_BY_252              0xA000FC00
#define PLLN_DIV_BY_253              0xA000FD00
#define PLLN_DIV_BY_254              0xA000FE00
#define PLLN_DIV_BY_255              0xA000FF00
#define PLLN_DIV_BY_256              0xA0001000
#define PLLN_DIV_BY_257              0xA0001010
#define PLLN_DIV_BY_258              0xA0001020
#define PLLN_DIV_BY_259              0xA0001030
#define PLLN_DIV_BY_260              0xA0001040
#define PLLN_DIV_BY_261              0xA0001050
#define PLLN_DIV_BY_262              0xA0001060
#define PLLN_DIV_BY_263              0xA0001070
#define PLLN_DIV_BY_264              0xA0001080
#define PLLN_DIV_BY_265              0xA0001090
#define PLLN_DIV_BY_266              0xA00010A0
#define PLLN_DIV_BY_267              0xA00010B0
#define PLLN_DIV_BY_268              0xA00010C0
#define PLLN_DIV_BY_269              0xA00010D0
#define PLLN_DIV_BY_270              0xA00010E0
#define PLLN_DIV_BY_271              0xA00010F0
#define PLLN_DIV_BY_272              0xA0001100
#define PLLN_DIV_BY_273              0xA0001110
#define PLLN_DIV_BY_274              0xA0001120
#define PLLN_DIV_BY_275              0xA0001130
#define PLLN_DIV_BY_276              0xA0001140
#define PLLN_DIV_BY_277              0xA0001150
#define PLLN_DIV_BY_278              0xA0001160
#define PLLN_DIV_BY_279              0xA0001170
#define PLLN_DIV_BY_280              0xA0001180
#define PLLN_DIV_BY_281              0xA0001190
#define PLLN_DIV_BY_282              0xA00011A0
#define PLLN_DIV_BY_283              0xA00011B0
#define PLLN_DIV_BY_284              0xA00011C0
#define PLLN_DIV_BY_285              0xA00011D0
#define PLLN_DIV_BY_286              0xA00011E0
#define PLLN_DIV_BY_287              0xA00011F0
#define PLLN_DIV_BY_288              0xA0001200
#define PLLN_DIV_BY_289              0xA0001210
#define PLLN_DIV_BY_290              0xA0001220
#define PLLN_DIV_BY_291              0xA0001230
#define PLLN_DIV_BY_292              0xA0001240
#define PLLN_DIV_BY_293              0xA0001250
#define PLLN_DIV_BY_294              0xA0001260
#define PLLN_DIV_BY_295              0xA0001270
#define PLLN_DIV_BY_296              0xA0001280
#define PLLN_DIV_BY_297              0xA0001290
#define PLLN_DIV_BY_298              0xA00012A0
#define PLLN_DIV_BY_299              0xA00012B0
#define PLLN_DIV_BY_300              0xA00012C0
#define PLLN_DIV_BY_301              0xA00012D0
#define PLLN_DIV_BY_302              0xA00012E0
#define PLLN_DIV_BY_303              0xA00012F0
#define PLLN_DIV_BY_304              0xA0001300
#define PLLN_DIV_BY_305              0xA0001310
#define PLLN_DIV_BY_306              0xA0001320
#define PLLN_DIV_BY_307              0xA0001330
#define PLLN_DIV_BY_308              0xA0001340
#define PLLN_DIV_BY_309              0xA0001350
#define PLLN_DIV_BY_310              0xA0001360
#define PLLN_DIV_BY_311              0xA0001370
#define PLLN_DIV_BY_312              0xA0001380
#define PLLN_DIV_BY_313              0xA0001390
#define PLLN_DIV_BY_314              0xA00013A0
#define PLLN_DIV_BY_315              0xA00013B0
#define PLLN_DIV_BY_316              0xA00013C0
#define PLLN_DIV_BY_317              0xA00013D0
#define PLLN_DIV_BY_318              0xA00013E0
#define PLLN_DIV_BY_319              0xA00013F0
#define PLLN_DIV_BY_320              0xA0001400
#define PLLN_DIV_BY_321              0xA0001410
#define PLLN_DIV_BY_322              0xA0001420
#define PLLN_DIV_BY_323              0xA0001430
#define PLLN_DIV_BY_324              0xA0001440
#define PLLN_DIV_BY_325              0xA0001450
#define PLLN_DIV_BY_326              0xA0001460
#define PLLN_DIV_BY_327              0xA0001470
#define PLLN_DIV_BY_328              0xA0001480
#define PLLN_DIV_BY_329              0xA0001490
#define PLLN_DIV_BY_330              0xA00014A0
#define PLLN_DIV_BY_331              0xA00014B0
#define PLLN_DIV_BY_332              0xA00014C0
#define PLLN_DIV_BY_333              0xA00014D0
#define PLLN_DIV_BY_334              0xA00014E0
#define PLLN_DIV_BY_335              0xA00014F0
#define PLLN_DIV_BY_336              0xA0001500
#define PLLN_DIV_BY_337              0xA0001510
#define PLLN_DIV_BY_338              0xA0001520
#define PLLN_DIV_BY_339              0xA0001530
#define PLLN_DIV_BY_340              0xA0001540
#define PLLN_DIV_BY_341              0xA0001550
#define PLLN_DIV_BY_342              0xA0001560
#define PLLN_DIV_BY_343              0xA0001570
#define PLLN_DIV_BY_344              0xA0001580
#define PLLN_DIV_BY_345              0xA0001590
#define PLLN_DIV_BY_346              0xA00015A0
#define PLLN_DIV_BY_347              0xA00015B0
#define PLLN_DIV_BY_348              0xA00015C0
#define PLLN_DIV_BY_349              0xA00015D0
#define PLLN_DIV_BY_350              0xA00015E0
#define PLLN_DIV_BY_351              0xA00015F0
#define PLLN_DIV_BY_352              0xA0001600
#define PLLN_DIV_BY_353              0xA0001610
#define PLLN_DIV_BY_354              0xA0001620
#define PLLN_DIV_BY_355              0xA0001630
#define PLLN_DIV_BY_356              0xA0001640
#define PLLN_DIV_BY_357              0xA0001650
#define PLLN_DIV_BY_358              0xA0001660
#define PLLN_DIV_BY_359              0xA0001670
#define PLLN_DIV_BY_360              0xA0001680
#define PLLN_DIV_BY_361              0xA0001690
#define PLLN_DIV_BY_362              0xA00016A0
#define PLLN_DIV_BY_363              0xA00016B0
#define PLLN_DIV_BY_364              0xA00016C0
#define PLLN_DIV_BY_365              0xA00016D0
#define PLLN_DIV_BY_366              0xA00016E0
#define PLLN_DIV_BY_367              0xA00016F0
#define PLLN_DIV_BY_368              0xA0001700
#define PLLN_DIV_BY_369              0xA0001710
#define PLLN_DIV_BY_370              0xA0001720
#define PLLN_DIV_BY_371              0xA0001730
#define PLLN_DIV_BY_372              0xA0001740
#define PLLN_DIV_BY_373              0xA0001750
#define PLLN_DIV_BY_374              0xA0001760
#define PLLN_DIV_BY_375              0xA0001770
#define PLLN_DIV_BY_376              0xA0001780
#define PLLN_DIV_BY_377              0xA0001790
#define PLLN_DIV_BY_378              0xA00017A0
#define PLLN_DIV_BY_379              0xA00017B0
#define PLLN_DIV_BY_380              0xA00017C0
#define PLLN_DIV_BY_381              0xA00017D0
#define PLLN_DIV_BY_382              0xA00017E0
#define PLLN_DIV_BY_383              0xA00017F0
#define PLLN_DIV_BY_384              0xA0001800
#define PLLN_DIV_BY_385              0xA0001810
#define PLLN_DIV_BY_386              0xA0001820
#define PLLN_DIV_BY_387              0xA0001830
#define PLLN_DIV_BY_388              0xA0001840
#define PLLN_DIV_BY_389              0xA0001850
#define PLLN_DIV_BY_390              0xA0001860
#define PLLN_DIV_BY_391              0xA0001870
#define PLLN_DIV_BY_392              0xA0001880
#define PLLN_DIV_BY_393              0xA0001890
#define PLLN_DIV_BY_394              0xA00018A0
#define PLLN_DIV_BY_395              0xA00018B0
#define PLLN_DIV_BY_396              0xA00018C0
#define PLLN_DIV_BY_397              0xA00018D0
#define PLLN_DIV_BY_398              0xA00018E0
#define PLLN_DIV_BY_399              0xA00018F0
#define PLLN_DIV_BY_400              0xA0001900
#define PLLN_DIV_BY_401              0xA0001910
#define PLLN_DIV_BY_402              0xA0001920
#define PLLN_DIV_BY_403              0xA0001930
#define PLLN_DIV_BY_404              0xA0001940
#define PLLN_DIV_BY_405              0xA0001950
#define PLLN_DIV_BY_406              0xA0001960
#define PLLN_DIV_BY_407              0xA0001970
#define PLLN_DIV_BY_408              0xA0001980
#define PLLN_DIV_BY_409              0xA0001990
#define PLLN_DIV_BY_410              0xA00019A0
#define PLLN_DIV_BY_411              0xA00019B0
#define PLLN_DIV_BY_412              0xA00019C0
#define PLLN_DIV_BY_413              0xA00019D0
#define PLLN_DIV_BY_414              0xA00019E0
#define PLLN_DIV_BY_415              0xA00019F0
#define PLLN_DIV_BY_416              0xA0001A00
#define PLLN_DIV_BY_417              0xA0001A10
#define PLLN_DIV_BY_418              0xA0001A20
#define PLLN_DIV_BY_419              0xA0001A30
#define PLLN_DIV_BY_420              0xA0001A40
#define PLLN_DIV_BY_421              0xA0001A50
#define PLLN_DIV_BY_422              0xA0001A60
#define PLLN_DIV_BY_423              0xA0001A70
#define PLLN_DIV_BY_424              0xA0001A80
#define PLLN_DIV_BY_425              0xA0001A90
#define PLLN_DIV_BY_426              0xA0001AA0
#define PLLN_DIV_BY_427              0xA0001AB0
#define PLLN_DIV_BY_428              0xA0001AC0
#define PLLN_DIV_BY_429              0xA0001AD0
#define PLLN_DIV_BY_430              0xA0001AE0
#define PLLN_DIV_BY_431              0xA0001AF0
#define PLLN_DIV_BY_432              0xA0001B00

#define PLLM_DIV_BY_2                0xA000002
#define PLLM_DIV_BY_3                0xA000003
#define PLLM_DIV_BY_4                0xA000004
#define PLLM_DIV_BY_5                0xA000005
#define PLLM_DIV_BY_6                0xA000006
#define PLLM_DIV_BY_7                0xA000007
#define PLLM_DIV_BY_8                0xA000008
#define PLLM_DIV_BY_9                0xA000009
#define PLLM_DIV_BY_10               0xA00000A
#define PLLM_DIV_BY_11               0xA00000B
#define PLLM_DIV_BY_12               0xA00000C
#define PLLM_DIV_BY_13               0xA00000D
#define PLLM_DIV_BY_14               0xA00000E
#define PLLM_DIV_BY_15               0xA00000F
#define PLLM_DIV_BY_16               0xA0000010
#define PLLM_DIV_BY_17               0xA0000011
#define PLLM_DIV_BY_18               0xA0000012
#define PLLM_DIV_BY_19               0xA0000013
#define PLLM_DIV_BY_20               0xA0000014
#define PLLM_DIV_BY_21               0xA0000015
#define PLLM_DIV_BY_22               0xA0000016
#define PLLM_DIV_BY_23               0xA0000017
#define PLLM_DIV_BY_24               0xA0000018
#define PLLM_DIV_BY_25               0xA0000019
#define PLLM_DIV_BY_26               0xA000001A
#define PLLM_DIV_BY_27               0xA000001B
#define PLLM_DIV_BY_28               0xA000001C
#define PLLM_DIV_BY_29               0xA000001D
#define PLLM_DIV_BY_30               0xA000001E
#define PLLM_DIV_BY_31               0xA000001F
#define PLLM_DIV_BY_32               0xA0000020
#define PLLM_DIV_BY_33               0xA0000021
#define PLLM_DIV_BY_34               0xA0000022
#define PLLM_DIV_BY_35               0xA0000023
#define PLLM_DIV_BY_36               0xA0000024
#define PLLM_DIV_BY_37               0xA0000025
#define PLLM_DIV_BY_38               0xA0000026
#define PLLM_DIV_BY_39               0xA0000027
#define PLLM_DIV_BY_40               0xA0000028
#define PLLM_DIV_BY_41               0xA0000029
#define PLLM_DIV_BY_42               0xA000002A
#define PLLM_DIV_BY_43               0xA000002B
#define PLLM_DIV_BY_44               0xA000002C
#define PLLM_DIV_BY_45               0xA000002D
#define PLLM_DIV_BY_46               0xA000002E
#define PLLM_DIV_BY_47               0xA000002F
#define PLLM_DIV_BY_48               0xA0000030
#define PLLM_DIV_BY_49               0xA0000031
#define PLLM_DIV_BY_50               0xA0000032
#define PLLM_DIV_BY_51               0xA0000033
#define PLLM_DIV_BY_52               0xA0000034
#define PLLM_DIV_BY_53               0xA0000035
#define PLLM_DIV_BY_54               0xA0000036
#define PLLM_DIV_BY_55               0xA0000037
#define PLLM_DIV_BY_56               0xA0000038
#define PLLM_DIV_BY_57               0xA0000039
#define PLLM_DIV_BY_58               0xA000003A
#define PLLM_DIV_BY_59               0xA000003B
#define PLLM_DIV_BY_60               0xA000003C
#define PLLM_DIV_BY_61               0xA000003D
#define PLLM_DIV_BY_62               0xA000003E
#define PLLM_DIV_BY_63               0xA000003F


/**********************************************************
 *
 *      Select system clock
 *          Options[3]
 *                  1.HSI
 *                  2.HSE
 *                  3.PLL

 **********************************************************/
#define SYSTEM_CLOCK_HSI                  0x00000300
#define SYSTEM_CLOCK_HSE                  0x00000301
#define SYSTEM_CLOCK_PLL                  0x00000302

/**
 *
 *      Select system clock output
 *          Options[3]
 *                  1.MCO1
 *                  2.MCO2
 *                  3.MCO1_PRE
 *                  4.MCO2_PRE
 *
 **/
#define CLOCK_OUTPUT_MOC2_SYSCLK               0x00000300
#define CLOCK_OUTPUT_MOC2_PLLI2C               0x40000300
#define CLOCK_OUTPUT_MOC2_HSE                  0x80000300
#define CLOCK_OUTPUT_MOC2_PLL                  0xC0000300

#define MOC1_DIV_BY_1                          0x00000300
#define MOC1_DIV_BY_2                          0x04000300
#define MOC1_DIV_BY_3                          0x05000300
#define MOC1_DIV_BY_4                          0x06000300
#define MOC1_DIV_BY_5                          0x07000300

#define MOC2_DIV_BY_1                          0x00000300
#define MOC2_DIV_BY_2                          0x20000300
#define MOC2_DIV_BY_3                          0x28000300
#define MOC2_DIV_BY_4                          0x30000300
#define MOC2_DIV_BY_5                          0x38000300

#define CLOCK_OUTPUT_MOC1_HSI                  0x00000300
#define CLOCK_OUTPUT_MOC1_LSE                  0x40200300
#define CLOCK_OUTPUT_MOC1_HSE                  0x00400300
#define CLOCK_OUTPUT_MOC1_PLL                  0x00600300


#define RTC_DIV_BY_2                           0x00020300
#define RTC_DIV_BY_3                           0x00030300
#define RTC_DIV_BY_4                           0x00040300
#define RTC_DIV_BY_5                           0x00050300
#define RTC_DIV_BY_6                           0x00060300
#define RTC_DIV_BY_7                           0x00070300
#define RTC_DIV_BY_8                           0x00080300
#define RTC_DIV_BY_9                           0x00090300
#define RTC_DIV_BY_10                          0x000A0300
#define RTC_DIV_BY_11                          0x000B0300
#define RTC_DIV_BY_12                          0x000C0300
#define RTC_DIV_BY_13                          0x000D0300
#define RTC_DIV_BY_14                          0x000E0300
#define RTC_DIV_BY_15                          0x000F0300
#define RTC_DIV_BY_16                          0x00100300
#define RTC_DIV_BY_17                          0x00110300
#define RTC_DIV_BY_18                          0x00120300
#define RTC_DIV_BY_19                          0x00130300
#define RTC_DIV_BY_20                          0x00140300
#define RTC_DIV_BY_21                          0x00150300
#define RTC_DIV_BY_22                          0x00160300
#define RTC_DIV_BY_23                          0x00170300
#define RTC_DIV_BY_24                          0x00180300
#define RTC_DIV_BY_25                          0x00190300
#define RTC_DIV_BY_26                          0x001A0300
#define RTC_DIV_BY_27                          0x001B0300
#define RTC_DIV_BY_28                          0x001C0300
#define RTC_DIV_BY_29                          0x001D0300
#define RTC_DIV_BY_30                          0x001E0300
#define RTC_DIV_BY_31                          0x001F0300

#define APB1_BUS_DIV_BY_1                      0x00000000
#define APB1_BUS_DIV_BY_2                      0x00001300
#define APB1_BUS_DIV_BY_4                      0x00001700
#define APB1_BUS_DIV_BY_8                      0x00001B00
#define APB1_BUS_DIV_BY_16                     0x00001F00

#define APB2_BUS_DIV_BY_1                      0x00000300
#define APB2_BUS_DIV_BY_2                      0x00008300
#define APB2_BUS_DIV_BY_4                      0x0000A300
#define APB2_BUS_DIV_BY_8                      0x0000C300
#define BUS_APB2_DIV_BY_16                     0x0000E300

#define SYSTEM_CLOCK_DIV_BY_1                  0x00000300
#define SYSTEM_CLOCK_DIV_BY_2                  0x00000380
#define SYSTEM_CLOCK_DIV_BY_4                  0x00000390
#define SYSTEM_CLOCK_DIV_BY_8                  0x000003A0
#define SYSTEM_CLOCK_DIV_BY_16                 0x000003B0
#define SYSTEM_CLOCK_DIV_BY_64                 0x000003C0
#define SYSTEM_CLOCK_DIV_BY_128                0x000003D0
#define SYSTEM_CLOCK_DIV_BY_256                0x000003E0
#define SYSTEM_CLOCK_DIV_BY_512                0x000003F0



typedef enum
{
     DISABLE_PERIPHERAL =0,
    ENABLE_PERIPHERAL ,
}ENM_PeripheralControl_t;

typedef enum
{
     CLOCK_OUTPUT_MOC_1 =0,
     CLOCK_OUTPUT_MOC_2 ,
}ENM_CLOCK_OUTPUT_t;

typedef struct
    {
        vuint32_t CR;
        vuint32_t PLLCFGR;
        vuint32_t CFGR;
        vuint32_t CIR;
        vuint32_t AHB1RSTR;
        vuint32_t AHB2RSTR;
        vuint32_t reserved1;
        vuint32_t reserved2;
        vuint32_t APB1RSTR;
        vuint32_t APB2RSTR;
        vuint32_t reserved3;
        vuint32_t reserved4;
        vuint32_t AHB1ENR;
        vuint32_t AHB2ENR;
        vuint32_t reserved5;
        vuint32_t reserved6;
        vuint32_t APB1ENR;
        vuint32_t APB2ENR;
        vuint32_t reserved7;
        vuint32_t reserved8;
        vuint32_t AHB1LPENR;
        vuint32_t AHB2LPENR;
        vuint32_t reserved9;
        vuint32_t reserved10;
        vuint32_t APB1LPENR;
        vuint32_t APB2LPENR;
        vuint32_t reserved11;
        vuint32_t reserved12;
        vuint32_t BDCR;
        vuint32_t CSR;
        vuint32_t reserved13;
        vuint32_t reserved14;
        vuint32_t SSCGR;
        vuint32_t PLLI2SCFGR;
        vuint32_t reserved15;
        vuint32_t DCKCFGR;
    }RCC_REG;

#define RCC ((volatile RCC_REG *)0x40023800)
  /*typedef RCC_REG* Ptr_to_RCC;*/
typedef enum
{
    enmRCC_Status_OK=0,
    enmRCC_Status_NOT_OK,
    enmRCC_Status_NULL_Pointer,
    enmRCC_Status_Wrong_BUS,
    enmRCC_Status_Wrong_Arguments,
    enmRCC_Status_NOT_Ready,
    enmRCC_Status_MORE_THAN_ONE_OPTION,
    enmRCC_Status_TIME_OUT
}ENM_ERROR_STATUS_t;




/**
 *
 *   Description: This function is used to enable different Clocks
 *   Note :- enable only one clock at a time
 *              @param
 *                       1.CLOCK_HSI
 *                       2.CLOCK_HSE
 *                       3.CLOCK_HSE_BYPASS
 *                       4.CLOCK_PLL
 *                       5.CLOCK_PLLI2S
 *
 **/
ENM_ERROR_STATUS_t rcc_EnableClock(uint32_t Clock);

/**
 *
 *   Description: This function is used to disable different Clocks
 *              @param
 *                       1.Clock_HSI
 *                       2.Clock_HSE
 *                       3.Clock_HSE_BYPASS
 *                       4.Clock_PLL
 *                       5.Clock_PLLI2S
 *
 **/
ENM_ERROR_STATUS_t rcc_DisableClock(uint32_t Clock);

/**
 *
 *   Description: This function is used Select and change system clock
 *          @param
 *                  1.SYSTEM_CLOCK_HSI
 *                  2.SYSTEM_CLOCK_HSE
 *                  3.SYSTEM_CLOCK_PLL
 **/
ENM_ERROR_STATUS_t rcc_ChangeSystemClock(uint32_t SystemClock);

/**
 *
 *    Description: this function is used to control Peripheral Clock For AHB1 Bus
 *          @param
 *                  1.BUS_AHB1_GPIOA
 *                  2.BUS_AHB1_GPIOB
 *                  3.BUS_AHB1_GPIOC
 *                  4.BUS_AHB1_GPIOD
 *                  5.BUS_AHB1_GPIOE
 *                  6.BUS_AHB1_GPIOH
 *                  7.BUS_AHB1_CRC
 *                  8.BUS_AHB1_DMA1
 *                  9.BUS_AHB1_DMA2
 *                  10BUS_AHB1_ALL
 *
 **/
ENM_ERROR_STATUS_t rcc_AHP1BusPeripheralControl(ENM_PeripheralControl_t StatePeripheral ,uint32_t Peripheral);

/**
 *
 *   Description: this function is used to control Peripheral Clock For AHB2 Bus
 *          @param
 *                  1.BUS_AHB2_OTGFS
 *
 **/
ENM_ERROR_STATUS_t rcc_AHP2BusPeripheralControl(ENM_PeripheralControl_t StatePeripheral ,uint32_t Peripheral);

/**
 *
 *   Description: this function is used to control Peripheral Clock For APB1 Bus
 *          @param
 *                  01.BUS_APB1_TIM2
 *                  02.BUS_APB1_TIM3
 *                  03.BUS_APB1_TIM4
 *                  04.BUS_APB1_TIM5
 *                  05.BUS_APB1_WWDG
 *                  06.BUS_APB1_SPI2
 *                  07.BUS_APB1_SPI3
 *                  08.BUS_APB1_USART2
 *                  09.BUS_APB1_I2C1
 *                  10.BUS_APB1_I2C2
 *                  11.BUS_APB1_I2C3
 *                  12.BUS_APB1_PWR
 *
 **/
ENM_ERROR_STATUS_t rcc_APB1BusPeripheralControl(ENM_PeripheralControl_t StatePeripheral ,uint32_t Peripheral);

/**********************************************************
 *
 *   Description: this function is used to Control Peripheral Clock For APB2 Bus
 *          @param
 *                  01.BUS_APB2_TIM1
 *                  02.BUS_APB2_USART1
 *                  03.BUS_APB2_USART6
 *                  04.BUS_APB2_ADC1
 *                  05.BUS_APB2_SDIO
 *                  06.BUS_APB2_SPI1
 *                  07.BUS_APB2_SPI4
 *                  08.BUS_APB2_SYSCFG
 *                  09.BUS_APB2_TIM9
 *                  10.BUS_APB2_TIM10
 *                  11.BUS_APB2_TIM11
 *
 **********************************************************/
ENM_ERROR_STATUS_t rcc_APB2BusPeripheralControl(ENM_PeripheralControl_t StatePeripheral ,uint32_t Peripheral);






/**********************************************************
 *
 *   Description: this function is responsible for controlling the Clock Security System
 *          @param
 *                 1.CLOCK_SECURITY_SYSTEM_ENABLE
 *                 2.CLOCK_SECURITY_SYSTEM_DISABLE
 *
 **********************************************************/
ENM_ERROR_STATUS_t rcc_EnableClockSecurity(uint32_t State);

/**********************************************************
 *
 *   Description: this function is responsible for configuring PLL Clock
 *   Note :- you can OR ( || ) All the pll configuration
 *      @param
 *          PLLQ[14]        2<=PLLQ<=15
 *              01.PLLQ_DIV_BY_2
 *              02.PLLQ_DIV_BY_3
 *              03.PLLQ_DIV_BY_4
 *              04.PLLQ_DIV_BY_5
 *              05.PLLQ_DIV_BY_6
 *              06.PLLQ_DIV_BY_7
 *              07.PLLQ_DIV_BY_8
 *              08.PLLQ_DIV_BY_9
 *              09.PLLQ_DIV_BY_10
 *              10.PLLQ_DIV_BY_11
 *              11.PLLQ_DIV_BY_12
 *              12.PLLQ_DIV_BY_13
 *              13.PLLQ_DIV_BY_14
 *              14.PLLQ_DIV_BY_15
 *          PLLSRC[2]
 *              1.PLLSRC_HSI
 *              1 PLLSRC_HSE
 *          PLLP[2]
 *              1.PLLP_DIV_BY_2
 *              2.PLLP_DIV_BY_4
 *              3.PLLP_DIV_BY_6
 *              4.PLLP_DIV_BY_8
 *
 *          PLLN[X] with 192 ≤PLLN ≤432
 *                PLLN_DIV_BY_192
 *                ...
 *                ...
 *                PLLN_DIV_BY_432
 *
 *          PLLM with 2 ≤PLLM ≤63
 *                PLLM_DIV_BY_2
 *                ...
 *                ...
 *                PLLM_DIV_BY_63
 *
 **********************************************************/
ENM_ERROR_STATUS_t rcc_PLLConfiguration(uint32_t PLL_Configuration );

/**********************************************************
 *
 *   Description: this function is responsible for Selecting clock output
 *
 *          @param
 *                          CLOCK_OUTPUT_MOC_1
 *                          CLOCK_OUTPUT_MOC_2
 *          @param
 *              MCO1[4]
 *                        1.CLOCK_OUTPUT_MOC1_HSI
 *                        2.CLOCK_OUTPUT_MOC1_LSE
 *                        3.CLOCK_OUTPUT_MOC1_HSE
 *                        4.CLOCK_OUTPUT_MOC1_PLL
 *              MCO2[4]
 *                        1.CLOCK_OUTPUT_MOC2_SYSCLK
 *                        2.CLOCK_OUTPUT_MOC2_PLLI2C
 *                        3.CLOCK_OUTPUT_MOC2_HSE
 *                        4.CLOCK_OUTPUT_MOC2_PLL
 *          @param
 *              MCO1[5]
 *                         1.MOC1_DIV_BY_1
 *                         2.MOC1_DIV_BY_2
 *                         3.MOC1_DIV_BY_3
 *                         4.MOC1_DIV_BY_4
 *                         5.MOC1_DIV_BY_5
 *               MCO2[5]
 *                         1.MOC2_DIV_BY_1
 *                         2.MOC2_DIV_BY_2
 *                         3.MOC2_DIV_BY_3
 *                         4.MOC2_DIV_BY_4
 *                         5.MOC2_DIV_BY_5
 *
 **********************************************************/
ENM_ERROR_STATUS_t rcc_ClockOutputControl(ENM_CLOCK_OUTPUT_t ClockOutNumber ,uint32_t Clock, uint32_t DivFactor);


/**********************************************************
 *
 *   Description: this function is responsible for Selecting APB1 Bus Prescaler
 *          @param
 *                1.APB1_BUS_DIV_BY_1
 *                2.APB1_BUS_DIV_BY_2
 *                3.APB1_BUS_DIV_BY_4
 *                4.APB1_BUS_DIV_BY_8
 *                5.APB1_BUS_DIV_BY_16
 *
 **********************************************************/
ENM_ERROR_STATUS_t rcc_APB1BusPrescaler(uint32_t DivFactor);

/**********************************************************
 *
 *   Description: this function is responsible for Selecting APB2 Bus Prescaler
 *          @param
 *                1.APB2_BUS_DIV_BY_1
 *                2.APB2_BUS_DIV_BY_2
 *                3.APB2_BUS_DIV_BY_4
 *                4.APB2_BUS_DIV_BY_8
 *                5.APB2_BUS_DIV_BY_16
 *
 **********************************************************/
ENM_ERROR_STATUS_t rcc_APB2BusPrescaler(uint32_t DivFactor);

/**********************************************************
 *
 *   Description: this function is responsible for Selecting System clock Prescaler
 *          @param
 *                1.SYSTEM_CLOCK_DIV_BY_1
 *                2.SYSTEM_CLOCK_DIV_BY_2
 *                3.SYSTEM_CLOCK_DIV_BY_4
 *                4.SYSTEM_CLOCK_DIV_BY_8
 *                5.SYSTEM_CLOCK_DIV_BY_16
 *                6.SYSTEM_CLOCK_DIV_BY_64
 *                7.SYSTEM_CLOCK_DIV_BY_128
 *                8.SYSTEM_CLOCK_DIV_BY_256
 *                9.SYSTEM_CLOCK_DIV_BY_512
 *
 *
 *
 **********************************************************/
ENM_ERROR_STATUS_t rcc_SystemClockPrescaler(uint32_t DivFactor);


#endif /* MCAL_RCC_RCC_INTERFACE_H_ */

