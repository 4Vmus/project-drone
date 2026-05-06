#ifndef __SETTIMER_H
#define __SETTIMER_H
///// DEFINE //////////////////////////////////////////////////////////////////

//SetTimer ID


#define TID_MAIN_STATE						0
#define TID_BASE_10mSEC				    1
#define TID_BASE_50mSEC				    2
#define TID_BASE_100mSEC			    3
#define TID_BASE_200mSEC			    4
#define TID_BASE_500mSEC			    5
#define TID_BASE_1SEC				      6
#define TID_LAST					        TID_BASE_1SEC + 1




//SetTimer value
#define TID_1mSEC               1
#define TID_2mSEC               2
#define TID_3mSEC               3
#define TID_5mSEC               1*5
#define TID_10mSEC              1*10
#define TID_20mSEC              2*10
#define TID_30mSEC              3*10
#define TID_40mSEC              4*10
#define TID_50mSEC              5*10
#define TID_60mSEC              6*10
#define TID_70mSEC              7*10
#define TID_80mSEC              8*10
#define TID_90mSEC              9*10

#define TID_100mSEC             10*10
#define TID_110mSEC             11*10
#define TID_120mSEC             12*10
#define TID_130mSEC             13*10
#define TID_140mSEC             14*10
#define TID_150mSEC             15*10
#define TID_160mSEC             16*10
#define TID_170mSEC             17*10
#define TID_180mSEC             18*10
#define TID_190mSEC             19*10

#define TID_200mSEC             20*10
#define TID_210mSEC             21*10
#define TID_220mSEC             22*10
#define TID_230mSEC             23*10
#define TID_240mSEC             24*10
#define TID_250mSEC             25*10
#define TID_260mSEC             26*10
#define TID_270mSEC             27*10
#define TID_280mSEC             28*10
#define TID_290mSEC             29*10

#define TID_300mSEC             30*10
#define TID_310mSEC             31*10
#define TID_320mSEC             32*10
#define TID_330mSEC             33*10
#define TID_340mSEC             34*10
#define TID_350mSEC             35*10
#define TID_360mSEC             36*10
#define TID_370mSEC             37*10
#define TID_380mSEC             38*10
#define TID_390mSEC             39*10

#define TID_400mSEC             40*10
#define TID_410mSEC             41*10
#define TID_420mSEC             42*10
#define TID_430mSEC             43*10
#define TID_440mSEC             44*10
#define TID_450mSEC             45*10
#define TID_460mSEC             46*10
#define TID_470mSEC             47*10
#define TID_480mSEC             48*10
#define TID_490mSEC             49*10

#define TID_500mSEC             50*10
#define TID_510mSEC             51*10
#define TID_520mSEC             52*10
#define TID_530mSEC             53*10
#define TID_540mSEC             54*10
#define TID_550mSEC             55*10
#define TID_560mSEC             56*10
#define TID_570mSEC             57*10
#define TID_580mSEC             58*10
#define TID_590mSEC             59*10

#define TID_600mSEC             60*10
#define TID_610mSEC             61*10
#define TID_620mSEC             62*10
#define TID_630mSEC             63*10
#define TID_640mSEC             64*10
#define TID_650mSEC             65*10
#define TID_660mSEC             66*10
#define TID_670mSEC             67*10
#define TID_680mSEC             68*10
#define TID_690mSEC             69*10

#define TID_700mSEC             70*10
#define TID_710mSEC             71*10
#define TID_720mSEC             72*10
#define TID_730mSEC             73*10
#define TID_740mSEC             74*10
#define TID_750mSEC             75*10
#define TID_760mSEC             76*10
#define TID_770mSEC             77*10
#define TID_780mSEC             78*10
#define TID_790mSEC             79*10

#define TID_800mSEC             80*10
#define TID_810mSEC             81*10
#define TID_820mSEC             82*10
#define TID_830mSEC             83*10
#define TID_840mSEC             84*10
#define TID_850mSEC             85*10
#define TID_860mSEC             86*10
#define TID_870mSEC             87*10
#define TID_880mSEC             88*10
#define TID_890mSEC             89*10
                                 
#define TID_900mSEC             90*10
#define TID_910mSEC             91*10
#define TID_920mSEC             92*10
#define TID_930mSEC             93*10
#define TID_940mSEC             94*10
#define TID_950mSEC             95*10
#define TID_960mSEC             96*10
#define TID_970mSEC             97*10
#define TID_980mSEC             98*10
#define TID_990mSEC             99*10

#define TID_1000mSEC            100*10
#define TID_1010mSEC            101*10
#define TID_1020mSEC            102*10
#define TID_1030mSEC            103*10
#define TID_1040mSEC            104*10
#define TID_1050mSEC            105*10
#define TID_1060mSEC            106*10
#define TID_1070mSEC            107*10
#define TID_1080mSEC            108*10
#define TID_1090mSEC            109*10

#define TID_1100mSEC            110*10
#define TID_1110mSEC            111*10
#define TID_1120mSEC            112*10
#define TID_1130mSEC            113*10
#define TID_1140mSEC            114*10
#define TID_1150mSEC            115*10
#define TID_1160mSEC            116*10
#define TID_1170mSEC            117*10
#define TID_1180mSEC            118*10
#define TID_1190mSEC            119*10
                                  
#define TID_1200mSEC            120*10
#define TID_1210mSEC            121*10
#define TID_1220mSEC            122*10
#define TID_1230mSEC            123*10
#define TID_1240mSEC            124*10
#define TID_1250mSEC            125*10
#define TID_1260mSEC            126*10
#define TID_1270mSEC            127*10
#define TID_1280mSEC            128*10
#define TID_1290mSEC            129*10
                                  
#define TID_1300mSEC            130*10
#define TID_1310mSEC            131*10
#define TID_1320mSEC            132*10
#define TID_1330mSEC            133*10
#define TID_1340mSEC            134*10
#define TID_1350mSEC            135*10
#define TID_1360mSEC            136*10
#define TID_1370mSEC            137*10
#define TID_1380mSEC            138*10
#define TID_1390mSEC            139*10
                                  
#define TID_1400mSEC            140*10
#define TID_1410mSEC            141*10
#define TID_1420mSEC            142*10
#define TID_1430mSEC            143*10
#define TID_1440mSEC            144*10
#define TID_1450mSEC            145*10
#define TID_1460mSEC            146*10
#define TID_1470mSEC            147*10
#define TID_1480mSEC            148*10
#define TID_1490mSEC            149*10
                                  
#define TID_1500mSEC            150*10
#define TID_1510mSEC            151*10
#define TID_1520mSEC            152*10
#define TID_1530mSEC            153*10
#define TID_1540mSEC            154*10
#define TID_1550mSEC            155*10
#define TID_1560mSEC            156*10
#define TID_1570mSEC            157*10
#define TID_1580mSEC            158*10
#define TID_1590mSEC            159*10

#define TID_1600mSEC            160*10
#define	TID_1620mSEC			      162*10


#define TID_2260mSEC            226*10

#define TID_1SEC                100*10
#define TID_1_2SEC			        120*10
#define TID_1_5SEC			        150*10
#define TID_1_8SEC			        180*10
#define TID_2SEC                100*2*10
#define TID_2_5SEC              (100*2)+TID_500mSEC*10
#define TID_3SEC                100*3*10
#define TID_3SEC                100*3*10
#define TID_3_7SEC              (100*3)+TID_700mSEC*10
#define TID_4SEC                100*4*10
#define TID_4_5SEC              (100*4)+TID_500mSEC*10
#define TID_5_5SEC              (100*5)+TID_500mSEC*10
#define TID_5SEC				        100*5*10
#define TID_6SEC                100*6*10
#define TID_7SEC                100*7*10
#define TID_8SEC                100*8*10
#define TID_8_2SEC              (100*8)+TID_200mSEC*10
#define TID_10SEC               100*10*10
#define TID_15SEC               100*15*10
#define TID_30SEC               100*30*10

#define TID_1MIN                100*60*10		//60000
#define TID_2MIN                100*60*2*10
#define TID_2_30MIN             100*60*2+TID_30SEC*10
#define TID_3MIN                100*60*3*10
#define TID_4MIN                100*60*4*10
#define TID_5MIN                100*60*5*10


///// VARIABLES ///////////////////////////////////////////////////////////////
//SetTimer Struct
typedef struct
{
    unsigned int wCount;
    unsigned int bFinished;
    void (*func)(void);
} TIMER;




extern volatile TIMER  Timer[TID_LAST];

///// FUNCTION ////////////////////////////////////////////////////////////////
extern void SetTimer(unsigned int ID, unsigned int Interval, void (*func)(void));
extern void KillTimer(unsigned int ID);
extern void SetTimer_Finish_Time(void);
extern void SetTimer_Check(void);
extern void Init_SetTimer(void);

#endif
