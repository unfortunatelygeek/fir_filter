#include <stdint.h>

#define NUM_TAPS_FIR			((uint16_t)232)
#define numStages_IIR 15
#define NUM_TAPS_IIR 5*numStages_IIR

static int firCoeffINT_BP[NUM_TAPS_FIR] = {
		22,
		26,
		28,
		28,
		26,
		20,
		10,
		-1,
		-15,
		-30,
		-45,
		-59,
		-69,
		-75,
		-75,
		-69,
		-55,
		-35,
		-10,
		19,
		51,
		83,
		111,
		133,
		147,
		150,
		140,
		118,
		84,
		40,
		-11,
		-68,
		-123,
		-174,
		-215,
		-242,
		-252,
		-243,
		-213,
		-163,
		-97,
		-17,
		69,
		156,
		238,
		306,
		354,
		378,
		373,
		339,
		275,
		186,
		76,
		-44,
		-170,
		-289,
		-392,
		-470,
		-515,
		-522,
		-489,
		-416,
		-306,
		-168,
		-11,
		154,
		315,
		458,
		572,
		646,
		673,
		649,
		574,
		451,
		290,
		100,
		-103,
		-306,
		-491,
		-645,
		-754,
		-807,
		-801,
		-733,
		-606,
		-430,
		-217,
		17,
		256,
		481,
		674,
		820,
		906,
		924,
		872,
		753,
		574,
		349,
		94,
		-171,
		-427,
		-654,
		-834,
		-952,
		-1000,
		-971,
		-869,
		-701,
		-478,
		-218,
		60,
		335,
		585,
		792,
		940,
		1016,
		1016,
		940,
		792,
		585,
		335,
		60,
		-218,
		-478,
		-701,
		-869,
		-971,
		-1000,
		-952,
		-834,
		-654,
		-427,
		-171,
		94,
		349,
		574,
		753,
		872,
		924,
		906,
		820,
		674,
		481,
		256,
		17,
		-217,
		-430,
		-606,
		-733,
		-801,
		-807,
		-754,
		-645,
		-491,
		-306,
		-103,
		100,
		290,
		451,
		574,
		649,
		673,
		646,
		572,
		458,
		315,
		154,
		-11,
		-168,
		-306,
		-416,
		-489,
		-522,
		-515,
		-470,
		-392,
		-289,
		-170,
		-44,
		76,
		186,
		275,
		339,
		373,
		378,
		354,
		306,
		238,
		156,
		69,
		-17,
		-97,
		-163,
		-213,
		-243,
		-252,
		-242,
		-215,
		-174,
		-123,
		-68,
		-11,
		40,
		84,
		118,
		140,
		150,
		147,
		133,
		111,
		83,
		51,
		19,
		-10,
		-35,
		-55,
		-69,
		-75,
		-75,
		-69,
		-59,
		-45,
		-30,
		-15,
		-1,
		10,
		20,
		26,
		28,
		28,
		26,
		22,
};

float pCoeffs_Papoulis[NUM_TAPS_IIR] = {
		-0.004809079189758538,
		0.000000000000000000,
		0.004809079189758538,
		-1.972621180769796640,
		-0.991014143380059220,
		-0.004808077619045298,
		0.000000000000000000,
		0.004808077619045298,
		-1.971553963343847030,
		-0.990807748204756034,
		-0.006270951413705633,
		0.000000000000000000,
		0.006270951413705633,
		-1.974347870268532650,
		-0.991934760202094590,
		-0.006267386476686452,
		0.000000000000000000,
		0.006267386476686452,
		-1.971219989176736350,
		-0.991370860928448838,
		-0.008299902353179954,
		0.000000000000000000,
		0.008299902353179954,
		-1.976428657857877360,
		-0.993318394025093143,
		-0.008293509649630227,
		0.000000000000000000,
		0.008293509649630227,
		-1.971544377628177580,
		-0.992553325985339630,
		-0.010212155709167994,
		0.000000000000000000,
		0.010212155709167994,
		-1.978716667780299420,
		-0.995055798563271976,
		-0.010204399336458534,
		0.000000000000000000,
		0.010204399336458534,
		-1.972546017074517490,
		-0.994300030255368394,
		-0.011680190093799269,
		0.000000000000000000,
		0.011680190093799269,
		-1.981044792988907010,
		-0.997002585454860202,
		-0.011673815711014026,
		0.000000000000000000,
		0.011673815711014026,
		-1.974139564301675030,
		-0.996458478204333531,
		-0.012497329029943860,
		0.000000000000000000,
		0.012497329029943860,
		-1.983229792769316990,
		-0.998994738653404490,
		-0.012494847962433209,
		0.000000000000000000,
		0.012494847962433209,
		-1.976155953778969690,
		-0.998796410403948509,
};

float pCoeffs_Bessel[NUM_TAPS_IIR] = {
		-0.025780280677518329,
		0.000000000000000000,
		0.025780280677518329,
		-1.932100198929704640,
		-0.949792161690966252,
		-0.025725202982874500,
		0.000000000000000000,
		0.025725202982874500,
		-1.928584696129458820,
		-0.947762999816776919,
		-0.026205283073678632,
		0.000000000000000000,
		0.026205283073678632,
		-1.936955324112739070,
		-0.953286853377207866,
		-0.026042986053004747,
		0.000000000000000000,
		0.026042986053004747,
		-1.926575138476635860,
		-0.947382867691737296,
		-0.027037754588143267,
		0.000000000000000000,
		0.027037754588143267,
		-1.943094834372619540,
		-0.958176594399364867,
		-0.026777927515371860,
		0.000000000000000000,
		0.026777927515371860,
		-1.926364829073373920,
		-0.948968721056582254,
		-0.028372673654210513,
		0.000000000000000000,
		0.028372673654210513,
		-1.950604584733402590,
		-0.964530485833045237,
		-0.028035102125815094,
		0.000000000000000000,
		0.028035102125815094,
		-1.928448589749886420,
		-0.953054724533463959,
		-0.030420242334975974,
		0.000000000000000000,
		0.030420242334975974,
		-1.959834296771775450,
		-0.972674379560309443,
		-0.030044018792036709,
		0.000000000000000000,
		0.030044018792036709,
		-1.933750389758369440,
		-0.960644790933933401,
		-0.033743338380468710,
		0.000000000000000000,
		0.033743338380468710,
		-1.971924983069929690,
		-0.983697442622315066,
		-0.033418613371953482,
		0.000000000000000000,
		0.033418613371953482,
		-1.944540444735642250,
		-0.974230947137184611,
};

float pCoeffs_Chebyshev[NUM_TAPS_IIR] = {
		-0.005991540730286605,
		0.000000000000000000,
		0.005991540730286605,
		-1.970256065301738470,
		-0.988609278905328126,
		-0.005989890305448891,
		0.000000000000000000,
		0.005989890305448891,
		-1.969088702110876280,
		-0.988336957413720629,
		-0.007203093550829018,
		0.000000000000000000,
		0.007203093550829018,
		-1.972091703192099480,
		-0.989626751777556768,
		-0.007197677757002333,
		0.000000000000000000,
		0.007197677757002333,
		-1.968720898362509080,
		-0.988882680578817008,
		-0.008923882517727671,
		0.000000000000000000,
		0.008923882517727671,
		-1.974435076915363570,
		-0.991274583868968162,
		-0.008914729196442190,
		0.000000000000000000,
		0.008914729196442190,
		-1.969232107619814710,
		-0.990257822977029134,
		-0.010574020742414940,
		0.000000000000000000,
		0.010574020742414940,
		-1.977116688089808560,
		-0.993416140202281861,
		-0.010563189715231673,
		0.000000000000000000,
		0.010563189715231673,
		-1.970630353419772000,
		-0.992398578625570793,
		-0.011825941452947648,
		0.000000000000000000,
		0.011825941452947648,
		-1.979972188194653480,
		-0.995908643357051537,
		-0.011817083120724816,
		0.000000000000000000,
		0.011817083120724816,
		-1.972840620627834610,
		-0.995162648658739490,
		-0.012501014642234336,
		0.000000000000000000,
		0.012501014642234336,
		-1.982848802094768100,
		-0.998611902047683242,
		-0.012497588702914812,
		0.000000000000000000,
		0.012497588702914812,
		-1.975704644658095700,
		-0.998338229559642687,
};

float pCoeffs_Butterworth[NUM_TAPS_IIR] = {
		-0.012462382528959034,
		0.000000000000000000,
		0.012462382528959034,
		-1.957356328958664850,
		-0.975587227997376072,
		-0.012454940220142315,
		0.000000000000000000,
		0.012454940220142315,
		-1.955883199204155880,
		-0.975004624998990210,
		-0.012479198889426090,
		0.000000000000000000,
		0.012479198889426090,
		-1.960332119396708480,
		-0.977757121559415410,
		-0.012458872533616411,
		0.000000000000000000,
		0.012458872533616411,
		-1.956125430870043540,
		-0.976164532217394187,
		-0.012503025653798513,
		0.000000000000000000,
		0.012503025653798513,
		-1.964525741023045220,
		-0.981273778362731886,
		-0.012475269531483670,
		0.000000000000000000,
		0.012475269531483670,
		-1.958179005236898580,
		-0.979095397243573751,
		-0.012531630110548257,
		0.000000000000000000,
		0.012531630110548257,
		-1.969621578148413430,
		-0.985852521915587809,
		-0.012503873530606138,
		0.000000000000000000,
		0.012503873530606138,
		-1.961987202324168900,
		-0.983668935734516414,
		-0.012563218735417830,
		0.000000000000000000,
		0.012563218735417830,
		-1.975302314021319510,
		-0.991195541165531768,
		-0.012542882010162501,
		0.000000000000000000,
		0.012542882010162501,
		-1.967323524761294350,
		-0.989591042205550830,
		-0.012596505210648363,
		0.000000000000000000,
		0.012596505210648363,
		-1.981262390465300840,
		-0.997008112271294489,
		-0.012589046283379476,
		0.000000000000000000,
		0.012589046283379476,
		-1.973799128812205210,
		-0.996417741301603988,
};


float pCoeffs_Gauss[NUM_TAPS_IIR] = {
		-0.012485651035428426,
		0.000000000000000000,
		0.012485651035428426,
		-1.951191482077207830,
		-0.969215596273066526,
		-0.012618504961251871,
		0.000000000000000000,
		0.012618504961251871,
		-1.961410054291755630,
		-0.979528562458715446,
		-0.012736522206452015,
		0.000000000000000000,
		0.012736522206452015,
		-1.959793754115776610,
		-0.976767935098835083,
		-0.012716894320586916,
		0.000000000000000000,
		0.012716894320586916,
		-1.955991637395758650,
		-0.975262666294993474,
		-0.013042400721138360,
		0.000000000000000000,
		0.013042400721138360,
		-1.964320394310401060,
		-0.980436712640744834,
		-0.013010457972045577,
		0.000000000000000000,
		0.013010457972045577,
		-1.957673362781657820,
		-0.978035479571554012,
		-0.013386076653488406,
		0.000000000000000000,
		0.013386076653488406,
		-1.969595754368445920,
		-0.985101512287057446,
		-0.013351786249607870,
		0.000000000000000000,
		0.013351786249607870,
		-1.961316667676810570,
		-0.982578029896057803,
		-0.013679434286743531,
		0.000000000000000000,
		0.013679434286743531,
		-1.975424582462036000,
		-0.990533016650801401,
		-0.013652816649876836,
		0.000000000000000000,
		0.013652816649876836,
		-1.966659905941249290,
		-0.988605623486068397,
		-0.013860346090154515,
		0.000000000000000000,
		0.013860346090154515,
		-1.981576621509285600,
		-0.996500842390987796,
		-0.013849507162685466,
		0.000000000000000000,
		0.013849507162685466,
		-1.973359239516237150,
		-0.995721568894982201,
};

float pCoeffs_Gauss_narrow[NUM_TAPS_IIR] = {
		-0.020384435620409078,
		0.000000000000000000,
		0.020384435620409078,
		-1.941978696337710810,
		-0.959988771273521113,
		-0.020360705611723633,
		0.000000000000000000,
		0.020360705611723633,
		-1.939825061254447420,
		-0.958871225401540128,
		-0.020754239163339853,
		0.000000000000000000,
		0.020754239163339853,
		-1.944800812072398970,
		-0.961826081899713192,
		-0.020682677166735466,
		0.000000000000000000,
		0.020682677166735466,
		-1.938347234424074190,
		-0.958509641616587804,
		-0.021517069239109406,
		0.000000000000000000,
		0.021517069239109406,
		-1.948349316921433430,
		-0.964415314631653309,
		-0.021396624456065470,
		0.000000000000000000,
		0.021396624456065470,
		-1.937618246445108160,
		-0.959016865984012701,
		-0.022790538796785841,
		0.000000000000000000,
		0.022790538796785841,
		-1.952776161381973410,
		-0.967878511049898305,
		-0.022619782385799783,
		0.000000000000000000,
		0.022619782385799783,
		-1.937806306600082130,
		-0.960626753542492717,
		-0.024846915246898849,
		0.000000000000000000,
		0.024846915246898849,
		-1.958424387179125150,
		-0.972510484301599476,
		-0.024625140515276138,
		0.000000000000000000,
		0.024625140515276138,
		-1.939269834796285120,
		-0.963830201477228421,
		-0.028481592441719061,
		0.000000000000000000,
		0.028481592441719061,
		-1.966219529542057700,
		-0.979115429548457317,
		-0.028213809956285370,
		0.000000000000000000,
		0.028213809956285370,
		-1.942917349990701980,
		-0.969909836013353011,
};