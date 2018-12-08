#include "stdafx.h"
#include "numeric.h"

double Numeric::N00(double x) { return 0; }
double Numeric::N10(double x) { return 1. - x; }
double Numeric::N11(double x) { return x; }
double Numeric::N20(double x) { return 1. - 3. * x + 2. * x * x; }
double Numeric::N21(double x) { return 4. * x - 4. * x * x; }
double Numeric::N22(double x) { return 2. * x * x  - x; }

void Numeric::KEPQ(double m, double &K, double &E, double &KP, double &KQ, double &EP, double &EQ) {
	KP = ellipKP[0];
	KQ = ellipKQ[0];
	EP = ellipEP[0];
	EQ = ellipEQ[0];
	double m1 = 1. - m;
	for (int k = 1; k <= 10; k++) {
		double m1k = pow(m1, k);
		KP += ellipKP[k] * m1k;
		KQ += ellipKQ[k] * m1k;
		EP += ellipEP[k] * m1k;
		EQ += ellipEQ[k] * m1k;
	}
	K = KP - log(1. - m) * KQ;
	E = EP - log(1. - m) * EQ;
}

void Numeric::KEPQ(double m, double &K, double &E) {
	double KP = ellipKP[0], KQ = ellipKQ[0], EP = ellipEP[0], EQ = ellipEQ[0];
	double m1 = 1. - m;
	for (int k = 1; k <= 10; k++) {
		double m1k = pow(m1, k);
		KP += ellipKP[k] * m1k;
		KQ += ellipKQ[k] * m1k;
		EP += ellipEP[k] * m1k;
		EQ += ellipEQ[k] * m1k;
	}
	K = KP - log(m1) * KQ;
	E = EP - log(m1) * EQ;
}


const double Numeric::ellipKP[11] = { 1.38629436111989062502E0,9.65735902811690126535E-2,3.08851465246711995998E-2,1.49380448916805252718E-2,8.79078273952743772254E-3,6.18901033637687613229E-3,6.87489687449949877925E-3,9.85821379021226008714E-3,7.97404013220415179367E-3,2.28025724005875567385E-3,1.37982864606273237150E-4 };
const double Numeric::ellipKQ[11] = { 4.99999999999999999821E-1,1.24999999999870820058E-1,7.03124996963957469739E-2,4.88280347570998239232E-2,3.73774314173823228969E-2,3.01204715227604046988E-2,2.39089602715924892727E-2,1.54850516649762399335E-2,5.94058303753167793257E-3,9.14184723865917226571E-4,2.94078955048598507511E-5 };
const double Numeric::ellipEP[11] = { 1.00000000000000000299E0,4.43147180560990850618E-1,5.68051945617860553470E-2,2.18317996015557253103E-2,1.15688436810574127319E-2,7.58395289413514708519E-3,7.77395492516787092951E-3,1.07350949056076193403E-2,8.68786816565889628429E-3,2.50888492163602060990E-3,1.53552577301013293365E-4 };
const double Numeric::ellipEQ[11] = { 0.0,2.49999999999888314361E-1,9.37499997197644278445E-2,5.85936634471101055642E-2,4.27180926518931511717E-2,3.34833904888224918614E-2,2.61769742454493659583E-2,1.68862163993311317300E-2,6.50609489976927491433E-3,1.00962792679356715133E-3,3.27954898576485872656E-5 };

double(**Numeric::N[3])(double) = { Numeric::N0 ,Numeric::N1, Numeric::N2 };
double(*Numeric::N0[1])(double) = { Numeric::N00 };
double(*Numeric::N1[2])(double) = { Numeric::N10, Numeric::N11 };
double(*Numeric::N2[3])(double) = { Numeric::N20, Numeric::N21, Numeric::N22 };


///////////////


const double* Numeric::qd_GL_x[21] = { qd_GL_x01, qd_GL_x01, qd_GL_x02, qd_GL_x03, qd_GL_x04, qd_GL_x05, qd_GL_x06, qd_GL_x07, qd_GL_x08, qd_GL_x09, qd_GL_x10, qd_GL_x11, qd_GL_x12, qd_GL_x13, qd_GL_x14, qd_GL_x15, qd_GL_x16, qd_GL_x17, qd_GL_x18, qd_GL_x19, qd_GL_x20 };
const double* Numeric::qd_GL_w[21] = { qd_GL_w01, qd_GL_w01, qd_GL_w02, qd_GL_w03, qd_GL_w04, qd_GL_w05, qd_GL_w06, qd_GL_w07, qd_GL_w08, qd_GL_w09, qd_GL_w10, qd_GL_w11, qd_GL_w12, qd_GL_w13, qd_GL_w14, qd_GL_w15, qd_GL_w16, qd_GL_w17, qd_GL_w18, qd_GL_w19, qd_GL_w20 };

const double Numeric::qd_GL_x01[1] = { 0.5000000000000000 };
const double Numeric::qd_GL_x02[2] = { 0.2113248654051871, 0.7886751345948129 };
const double Numeric::qd_GL_x03[3] = { 0.1127016653792583, 0.5000000000000000, 0.8872983346207420 };
const double Numeric::qd_GL_x04[4] = { 0.0694318442029737, 0.3300094782075718, 0.6699905217924282, 0.9305681557970260 };
const double Numeric::qd_GL_x05[5] = { 0.0469100770306680, 0.2307653449471585, 0.5000000000000000, 0.7692346550528415, 0.9530899229693320 };
const double Numeric::qd_GL_x06[6] = { 0.0337652428984240, 0.1693953067668677, 0.3806904069584016, 0.6193095930415985, 0.8306046932331320, 0.9662347571015760 };
const double Numeric::qd_GL_x07[7] = { 0.0254460438286207, 0.1292344072003028, 0.2970774243113014, 0.5000000000000000, 0.7029225756886985, 0.8707655927996970, 0.9745539561713790 };
const double Numeric::qd_GL_x08[8] = { 0.0198550717512319, 0.1016667612931866, 0.2372337950418355, 0.4082826787521751, 0.5917173212478249, 0.7627662049581645, 0.8983332387068130, 0.9801449282487680 };
const double Numeric::qd_GL_x09[9] = { 0.0159198802461870, 0.0819844463366821, 0.1933142836497048, 0.3378732882980955, 0.5000000000000000, 0.6621267117019045, 0.8066857163502950, 0.9180155536633180, 0.9840801197538130 };
const double Numeric::qd_GL_x10[10] = { 0.0130467357414141, 0.0674683166555077, 0.1602952158504878, 0.2833023029353764, 0.4255628305091844, 0.5744371694908156, 0.7166976970646236, 0.8397047841495120, 0.9325316833444920, 0.9869532642585860 };
const double Numeric::qd_GL_x11[11] = { 0.0108856709269715, 0.0564687001159524, 0.1349239972129753, 0.2404519353965941, 0.3652284220238275, 0.5000000000000000, 0.6347715779761725, 0.7595480646034059, 0.8650760027870250, 0.9435312998840480, 0.9891143290730290 };
const double Numeric::qd_GL_x12[12] = { 0.0092196828766404, 0.0479413718147626, 0.1150486629028477, 0.2063410228566913, 0.3160842505009099, 0.4373832957442655, 0.5626167042557345, 0.6839157494990901, 0.7936589771433087, 0.8849513370971520, 0.9520586281852370, 0.9907803171233600 };
const double Numeric::qd_GL_x13[13] = { 0.0079084726407059, 0.0412008003885110, 0.0992109546333450, 0.1788253302798299, 0.2757536244817766, 0.3847708420224326, 0.5000000000000000, 0.6152291579775674, 0.7242463755182235, 0.8211746697201700, 0.9007890453666550, 0.9587991996114890, 0.9920915273592940 };
const double Numeric::qd_GL_x14[14] = { 0.0068580956515938, 0.0357825581682132, 0.0863993424651175, 0.1563535475941573, 0.2423756818209229, 0.3404438155360551, 0.4459725256463281, 0.5540274743536719, 0.6595561844639449, 0.7576243181790771, 0.8436464524058430, 0.9136006575348830, 0.9642174418317870, 0.9931419043484060 };
const double Numeric::qd_GL_x15[15] = { 0.0060037409897573, 0.0313633037996471, 0.0758967082947864, 0.1377911343199150, 0.2145139136957306, 0.3029243264612183, 0.3994029530012828, 0.5000000000000000, 0.6005970469987173, 0.6970756735387816, 0.7854860863042694, 0.8622088656800850, 0.9241032917052140, 0.9686366962003530, 0.9939962590102430 };
const double Numeric::qd_GL_x16[16] = { 0.0052995325041750, 0.0277124884633837, 0.0671843988060841, 0.1222977958224985, 0.1910618777986781, 0.2709916111713863, 0.3591982246103705, 0.4524937450811813, 0.5475062549188188, 0.6408017753896295, 0.7290083888286137, 0.8089381222013220, 0.8777022041775020, 0.9328156011939160, 0.9722875115366160, 0.9947004674958250 };
const double Numeric::qd_GL_x17[17] = { 0.0047122623427913, 0.0246622391156161, 0.0598804231365071, 0.1092429980515993, 0.1711644203916546, 0.2436547314567615, 0.3243841182730618, 0.4107579092520760, 0.5000000000000000, 0.5892420907479239, 0.6756158817269382, 0.7563452685432384, 0.8288355796083450, 0.8907570019484010, 0.9401195768634930, 0.9753377608843840, 0.9952877376572090 };
const double Numeric::qd_GL_x18[18] = { 0.0042174157895345, 0.0220880252143011, 0.0536987667512221, 0.0981475205137384, 0.1541564784698234, 0.2201145844630262, 0.2941244192685787, 0.3740568871542473, 0.4576124934791324, 0.5423875065208676, 0.6259431128457527, 0.7058755807314213, 0.7798854155369738, 0.8458435215301770, 0.9018524794862620, 0.9463012332487780, 0.9779119747856990, 0.9957825842104650 };
const double Numeric::qd_GL_x19[19] = { 0.0037965780782078, 0.0198959239325850, 0.0484220481925911, 0.0886426717314286, 0.1395169113323853, 0.1997273476691595, 0.2677146293120195, 0.3417179500181851, 0.4198206771798873, 0.5000000000000000, 0.5801793228201126, 0.6582820499818149, 0.7322853706879805, 0.8002726523308410, 0.8604830886676150, 0.9113573282685710, 0.9515779518074090, 0.9801040760674150, 0.9962034219217920 };
const double Numeric::qd_GL_x20[20] = { 0.0034357004074525, 0.0180140363610431, 0.0438827858743371, 0.0804415140888906, 0.1268340467699246, 0.1819731596367425, 0.2445664990245865, 0.3131469556422902, 0.3861070744291775, 0.4617367394332513, 0.5382632605667487, 0.6138929255708225, 0.6868530443577098, 0.7554335009754135, 0.8180268403632580, 0.8731659532300750, 0.9195584859111090, 0.9561172141256630, 0.9819859636389570, 0.9965642995925470 };

const double Numeric::qd_GL_w01[1] = { 1.0000000000000000 };
const double Numeric::qd_GL_w02[2] = { 0.5000000000000000, 0.5000000000000000 };
const double Numeric::qd_GL_w03[3] = { 0.2777777777777778, 0.4444444444444445, 0.2777777777777778 };
const double Numeric::qd_GL_w04[4] = { 0.1739274225687269, 0.3260725774312730, 0.3260725774312730, 0.1739274225687269 };
const double Numeric::qd_GL_w05[5] = { 0.1184634425280946, 0.2393143352496832, 0.2844444444444445, 0.2393143352496832, 0.1184634425280946 };
const double Numeric::qd_GL_w06[6] = { 0.0856622461895852, 0.1803807865240693, 0.2339569672863455, 0.2339569672863455, 0.1803807865240693, 0.0856622461895852 };
const double Numeric::qd_GL_w07[7] = { 0.0647424830844349, 0.1398526957446383, 0.1909150252525595, 0.2089795918367347, 0.1909150252525595, 0.1398526957446383, 0.0647424830844349 };
const double Numeric::qd_GL_w08[8] = { 0.0506142681451881, 0.1111905172266872, 0.1568533229389436, 0.1813418916891810, 0.1813418916891810, 0.1568533229389436, 0.1111905172266872, 0.0506142681451881 };
const double Numeric::qd_GL_w09[9] = { 0.0406371941807872, 0.0903240803474287, 0.1303053482014677, 0.1561735385200014, 0.1651196775006299, 0.1561735385200014, 0.1303053482014677, 0.0903240803474287, 0.0406371941807872 };
const double Numeric::qd_GL_w10[10] = { 0.0333356721543441, 0.0747256745752903, 0.1095431812579910, 0.1346333596549982, 0.1477621123573764, 0.1477621123573764, 0.1346333596549982, 0.1095431812579910, 0.0747256745752903, 0.0333356721543441 };
const double Numeric::qd_GL_w11[11] = { 0.0278342835580868, 0.0627901847324523, 0.0931451054638671, 0.1165968822959953, 0.1314022722551233, 0.1364625433889503, 0.1314022722551233, 0.1165968822959953, 0.0931451054638671, 0.0627901847324523, 0.0278342835580868 };
const double Numeric::qd_GL_w12[12] = { 0.0235876681932559, 0.0534696629976592, 0.0800391642716731, 0.1015837133615330, 0.1167462682691774, 0.1245735229067014, 0.1245735229067014, 0.1167462682691774, 0.1015837133615330, 0.0800391642716731, 0.0534696629976592, 0.0235876681932559 };
const double Numeric::qd_GL_w13[13] = { 0.0202420023826579, 0.0460607499188642, 0.0694367551098936, 0.0890729903809729, 0.1039080237684443, 0.1131415901314486, 0.1162757766154370, 0.1131415901314486, 0.1039080237684443, 0.0890729903809729, 0.0694367551098936, 0.0460607499188642, 0.0202420023826579 };
const double Numeric::qd_GL_w14[14] = { 0.0175597301658759, 0.0400790435798801, 0.0607592853439516, 0.0786015835790968, 0.0927691987389689, 0.1025992318606478, 0.1076319267315789, 0.1076319267315789, 0.1025992318606478, 0.0927691987389689, 0.0786015835790968, 0.0607592853439516, 0.0400790435798801, 0.0175597301658759 };
const double Numeric::qd_GL_w15[15] = { 0.0153766209980586, 0.0351830237440541, 0.0535796102335860, 0.0697853389630772, 0.0831346029084970, 0.0930805000077811, 0.0992157426635558, 0.1012891209627806, 0.0992157426635558, 0.0930805000077811, 0.0831346029084970, 0.0697853389630772, 0.0535796102335860, 0.0351830237440541, 0.0153766209980586 };
const double Numeric::qd_GL_w16[16] = { 0.0135762297058771, 0.0311267619693239, 0.0475792558412464, 0.0623144856277669, 0.0747979944082884, 0.0845782596975013, 0.0913017075224618, 0.0947253052275343, 0.0947253052275343, 0.0913017075224618, 0.0845782596975013, 0.0747979944082884, 0.0623144856277669, 0.0475792558412464, 0.0311267619693239, 0.0135762297058771 };
const double Numeric::qd_GL_w17[17] = { 0.0120741514342740, 0.0277297646869936, 0.0425180741585896, 0.0559419235967020, 0.0675681842342627, 0.0770228805384051, 0.0840020510782250, 0.0882813526834963, 0.0897232351781033, 0.0882813526834963, 0.0840020510782250, 0.0770228805384051, 0.0675681842342627, 0.0559419235967020, 0.0425180741585896, 0.0277297646869936, 0.0120741514342740 };
const double Numeric::qd_GL_w18[18] = { 0.0108080067632417, 0.0248572744474849, 0.0382128651274445, 0.0504710220531436, 0.0612776033557392, 0.0703214573353253, 0.0773423375631326, 0.0821382418729164, 0.0845711914815718, 0.0845711914815718, 0.0821382418729164, 0.0773423375631326, 0.0703214573353253, 0.0612776033557392, 0.0504710220531436, 0.0382128651274445, 0.0248572744474849, 0.0108080067632417 };
const double Numeric::qd_GL_w19[19] = { 0.0097308941148632, 0.0224071133828498, 0.0345222713688206, 0.0457450108112250, 0.0557833227736670, 0.0643769812696681, 0.0713033510868033, 0.0763830210329298, 0.0794844216969772, 0.0805272249243919, 0.0794844216969772, 0.0763830210329298, 0.0713033510868033, 0.0643769812696681, 0.0557833227736670, 0.0457450108112250, 0.0345222713688206, 0.0224071133828498, 0.0097308941148632 };
const double Numeric::qd_GL_w20[20] = { 0.0088070035695761, 0.0203007149001935, 0.0313360241670545, 0.0416383707883524, 0.0509650599086202, 0.0590972659807592, 0.0658443192245883, 0.0710480546591910, 0.0745864932363019, 0.0763766935653629, 0.0763766935653629, 0.0745864932363019, 0.0710480546591910, 0.0658443192245883, 0.0590972659807592, 0.0509650599086202, 0.0416383707883524, 0.0313360241670545, 0.0203007149001935, 0.0088070035695761 };

const double* Numeric::qd_LOG_x[21] = { qd_LOG_x01, qd_LOG_x01, qd_LOG_x02, qd_LOG_x03, qd_LOG_x04, qd_LOG_x05, qd_LOG_x06, qd_LOG_x07, qd_LOG_x08, qd_LOG_x09, qd_LOG_x10, qd_LOG_x11, qd_LOG_x12, qd_LOG_x13, qd_LOG_x14, qd_LOG_x15, qd_LOG_x16, qd_LOG_x17, qd_LOG_x18, qd_LOG_x19, qd_LOG_x20 };
const double* Numeric::qd_LOG_w[21] = { qd_LOG_w01, qd_LOG_w01, qd_LOG_w02, qd_LOG_w03, qd_LOG_w04, qd_LOG_w05, qd_LOG_w06, qd_LOG_w07, qd_LOG_w08, qd_LOG_w09, qd_LOG_w10, qd_LOG_w11, qd_LOG_w12, qd_LOG_w13, qd_LOG_w14, qd_LOG_w15, qd_LOG_w16, qd_LOG_w17, qd_LOG_w18, qd_LOG_w19, qd_LOG_w20 };

const double Numeric::qd_LOG_x01[1] = { 2.50000000000000e-1 };
const double Numeric::qd_LOG_x02[2] = { 1.12008806166976e-1, 6.02276908118738e-1 };
const double Numeric::qd_LOG_x03[3] = { 6.38907930873254e-2, 3.68997063715619e-1, 7.66880303938941e-1 };
const double Numeric::qd_LOG_x04[4] = { 4.14484801993832e-2, 2.45274914320602e-1, 5.56165453560276e-1, 8.48982394532985e-1 };
const double Numeric::qd_LOG_x05[5] = { 2.91344721519721e-2, 1.73977213320898e-1, 4.11702520284902e-1, 6.77314174582820e-1, 8.94771361031008e-1 };
const double Numeric::qd_LOG_x06[6] = { 2.16340058441169e-2, 1.29583391154951e-1, 3.14020449914766e-1, 5.38657217351802e-1, 7.56915337377403e-1, 9.22668851372120e-1 };
const double Numeric::qd_LOG_x07[7] = { 1.67193554082585e-2, 1.00185677915675e-1, 2.46294246207931e-1, 4.33463493257033e-1, 6.32350988047766e-1, 8.11118626740106e-1, 9.40848166743348e-1 };
const double Numeric::qd_LOG_x08[8] = { 1.33202441608925e-2, 7.97504290138949e-2, 1.97871029326188e-1, 3.54153994351909e-1, 5.29458575234917e-1, 7.01814529939100e-1, 8.49379320441107e-1, 9.53326450056360e-1 };
const double Numeric::qd_LOG_x09[9] = { 1.08693360841755e-2, 6.49836663380079e-2, 1.62229398023883e-1, 2.93749903971675e-1, 4.46631881905468e-1, 6.05481662776129e-1, 7.54110137157164e-1, 8.77265828835838e-1, 9.62250559410282e-1 };
const double Numeric::qd_LOG_x10[10] = { 9.04263096219965e-3, 5.39712662225006e-2, 1.35311824639251e-1, 2.47052416287160e-1, 3.80212539609332e-1, 5.23792317971843e-1, 6.65775205516425e-1, 7.94190416011966e-1, 8.98161091219004e-1, 9.68847988718634e-1 };
const double Numeric::qd_LOG_x11[11] = { 7.64394117463771e-3, 4.55418282565789e-2, 1.14522297455125e-1, 2.10378581227034e-1, 3.26695553221693e-1, 4.55453246928813e-1, 5.87648356359084e-1, 7.13963850012561e-1, 8.25453217801812e-1, 9.14193921612543e-1, 9.73860256275586e-1 };
const double Numeric::qd_LOG_x12[12] = { 6.54872227908006e-3, 3.89468095604500e-2, 9.81502631060066e-2, 1.81138581590632e-1, 2.83220067667373e-1, 3.98434435163437e-1, 5.19952626792353e-1, 6.40510916716106e-1, 7.52865012051831e-1, 8.50240024162302e-1, 9.26749683223914e-1, 9.77756129689997e-1 };
const double Numeric::qd_LOG_x13[13] = { 5.67476625624267e-3, 3.36901087990325e-2, 8.50367544741750e-2, 1.57497559477889e-1, 2.47569578876843e-1, 3.50744312360855e-1, 4.61773746761610e-1, 5.74959466525561e-1, 6.84459880350430e-1, 7.84602568810347e-1, 8.70186428407888e-1, 9.36757829306751e-1, 9.80843451811591e-1 };
const double Numeric::qd_LOG_x14[14] = { 4.96600357386854e-3, 2.94325401188852e-2, 7.43762922245358e-2, 1.38138491989186e-1, 2.18055648498959e-1, 3.10662083918102e-1, 4.11872475177750e-1, 5.17179307398654e-1, 6.21864859728511e-1, 7.21220745208109e-1, 8.10765988071590e-1, 8.86454038034435e-1, 9.44859139461819e-1, 9.83331026485678e-1 };
const double Numeric::qd_LOG_x15[15] = { 4.38311017547540e-3, 2.59358981053306e-2, 6.55960954123162e-2, 1.22101934073332e-1, 1.93395262374007e-1, 2.76772838706102e-1, 3.69015127139743e-1, 4.66524328964707e-1, 5.65473473791817e-1, 6.61962919012456e-1, 7.52178883378786e-1, 8.32548033866190e-1, 8.99882050120898e-1, 9.51506188743410e-1, 9.85364468122132e-1 };
const double Numeric::qd_LOG_x16[16] = { 3.89783448711592e-3, 2.30289456168732e-2, 5.82803983062404e-2, 1.08678365091054e-1, 1.72609454909844e-1, 2.47937054470578e-1, 3.32094549129917e-1, 4.22183910581949e-1, 5.15082473381463e-1, 6.07556120447729e-1, 6.96375653228214e-1, 7.78432565873265e-1, 8.50850269715391e-1, 9.11086857222272e-1, 9.57025571703542e-1, 9.87047800247984e-1 };
const double Numeric::qd_LOG_x17[17] = { 3.48944942809365e-3, 2.05860406877611e-2, 5.21217916297223e-2, 9.73354259275744e-2, 1.54945857983249e-1, 2.23243954205450e-1, 3.00161598873464e-1, 3.83343519530540e-1, 4.70225073199601e-1, 5.58115277026492e-1, 6.44283151731502e-1, 7.26044960838813e-1, 8.00849737279702e-1, 8.66360460578840e-1, 9.20528319303556e-1, 9.61657532071674e-1, 9.88456918847435e-1 };
const double Numeric::qd_LOG_x18[18] = { 3.14246513800145e-3, 1.85133122080843e-2, 4.68891829953568e-2, 8.76681791779751e-2, 1.39821274385391e-1, 2.01966306570199e-1, 2.72420255500711e-1, 3.49252538662625e-1, 4.30342588559143e-1, 5.13441600439316e-1, 5.96237308519533e-1, 6.76420232632214e-1, 7.51749655041838e-1, 8.20117526905824e-1, 8.79608522893184e-1, 9.28554528829897e-1, 9.65581851992832e-1, 9.89648238497166e-1 };
const double Numeric::qd_LOG_x19[19] = { 2.84511472758003e-3, 1.67394868602341e-2, 4.24062333121213e-2, 7.93646495242485e-2, 1.26779524713245e-1, 1.83521965374816e-1, 2.48209751538999e-1, 3.19247560858021e-1, 3.94870226085803e-1, 4.73189256050998e-1, 5.52241966862257e-1, 6.30042214445635e-1, 7.04631556024242e-1, 7.74129598714736e-1, 8.36782282905287e-1, 8.91006879458074e-1, 9.35432532472656e-1, 9.68935159159729e-1, 9.90664392788623e-1 };
const double Numeric::qd_LOG_x20[20] = { 2.58832795592196e-3, 1.52096623495602e-2, 3.85365503721653e-2, 7.21816138158739e-2, 1.15460526487633e-1, 1.67442856275330e-1, 2.26983787260203e-1, 2.92754960941546e-1, 3.63277429857859e-1, 4.36957140090768e-1, 5.12122594678967e-1, 5.87064044914410e-1, 6.60073413314909e-1, 7.29484083929687e-1, 7.93709671987086e-1, 8.51280892789126e-1, 9.00879680854418e-1, 9.41369749129092e-1, 9.71822741075263e-1, 9.91538081438712e-1 };

const double Numeric::qd_LOG_w01[1] = { 1.00000000000000 };
const double Numeric::qd_LOG_w02[2] = { 7.18539319030384e-1, 2.81460680969616e-1 };
const double Numeric::qd_LOG_w03[3] = { 5.13404552232363e-1, 3.91980041201488e-1, 9.46154065661491e-2 };
const double Numeric::qd_LOG_w04[4] = { 3.83464068145135e-1, 3.86875317774763e-1, 1.90435126950142e-1, 3.92254871299598e-2 };
const double Numeric::qd_LOG_w05[5] = { 2.97893471782894e-1, 3.49776226513224e-1, 2.34488290044052e-1, 9.89304595166331e-2, 1.89115521431958e-2 };
const double Numeric::qd_LOG_w06[6] = { 2.38763662578548e-1, 3.08286573273947e-1, 2.45317426563210e-1, 1.42008756566477e-1, 5.54546223248863e-2, 1.01689586929323e-2 };
const double Numeric::qd_LOG_w07[7] = { 1.96169389425248e-1, 2.70302644247273e-1, 2.39681873007691e-1, 1.65775774810433e-1, 8.89432271376580e-2, 3.31943043565711e-2, 5.93278701512592e-3 };
const double Numeric::qd_LOG_w08[8] = { 1.64416604728003e-1, 2.37525610023306e-1, 2.26841984431919e-1, 1.75754079006070e-1, 1.12924030246759e-1, 5.78722107177821e-2, 2.09790737421330e-2, 3.68640710402762e-3 };
const double Numeric::qd_LOG_w09[9] = { 1.40068438748135e-1, 2.09772205201030e-1, 2.11427149896603e-1, 1.77156233938080e-1, 1.27799228033205e-1, 7.84789026115622e-2, 3.90225049853991e-2, 1.38672955495930e-2, 2.40804103639231e-3 };
const double Numeric::qd_LOG_w10[10] = { 1.20955131954571e-1, 1.86363542564072e-1, 1.95660873277760e-1, 1.73577142182907e-1, 1.35695672995484e-1, 9.36467585381105e-2, 5.57877273514159e-2, 2.71598108992333e-2, 9.51518260284851e-3, 1.63815763359826e-3 };
const double Numeric::qd_LOG_w11[11] = { 1.05652256099100e-1, 1.66571680600629e-1, 1.80563218287754e-1, 1.67278736773784e-1, 1.38697057401631e-1, 1.03833433365044e-1, 6.95366978887352e-2, 4.05416008035963e-2, 1.94354024762182e-2, 6.73742934245006e-3, 1.15248696105748e-3 };
const double Numeric::qd_LOG_w12[12] = { 9.31926914439313e-2, 1.49751827576322e-1, 1.66557454364593e-1, 1.59633559436988e-1, 1.38424831864836e-1, 1.10016570635721e-1, 7.99618217708290e-2, 5.24069548246418e-2, 3.00710888737612e-2, 1.42492455879983e-2, 4.89992458232176e-3, 8.34029038056903e-4 };
const double Numeric::qd_LOG_w13[13] = { 8.29004967932758e-2, 1.35368673165745e-1, 1.53773284392292e-1, 1.51458158509988e-1, 1.36040336537283e-1, 1.13176822881634e-1, 8.73744304800453e-2, 6.21602306418049e-2, 4.00877289341659e-2, 2.27238449399722e-2, 1.06712304129684e-2, 3.64649227597414e-3, 6.18270034851697e-4 };
const double Numeric::qd_LOG_w14[14] = { 7.42912250675104e-2, 1.22988772469323e-1, 1.42199306562523e-1, 1.43229297641264e-1, 1.32345083772085e-1, 1.14135875736676e-1, 9.22830380790736e-2, 6.97536732939376e-2, 4.88303236005136e-2, 3.11017960644161e-2, 1.74628119501961e-2, 8.14242342987594e-3, 2.76843641856394e-3, 4.67935914040560e-4 };
const double Numeric::qd_LOG_w15[15] = { 6.70099789164937e-2, 1.12264150286706e-1, 1.31760177039680e-1, 1.35217649061935e-1, 1.27881798645680e-1, 1.13532907490219e-1, 9.52052397843587e-2, 7.53893141673960e-2, 5.60784244926537e-2, 3.87682953750182e-2, 2.44514832687501e-2, 1.36246301382388e-2, 6.31644759859076e-3, 2.13888991594447e-3, 3.60613818335407e-4 };
const double Numeric::qd_LOG_w16[16] = { 6.07917100435912e-2, 1.02915677517582e-1, 1.22355662046009e-1, 1.27569246937016e-1, 1.23013574600071e-1, 1.11847244855486e-1, 9.65963851521243e-2, 7.93566643514731e-2, 6.18504945819652e-2, 4.54352465077267e-2, 3.10989747515818e-2, 1.94597659273608e-2, 1.07762549632055e-2, 4.97254289008764e-3, 1.67820111005119e-3, 2.82353764668436e-4 };
const double Numeric::qd_LOG_w17[17] = { 5.54350690606789e-2, 9.47187691894761e-2, 1.13880141162429e-1, 1.20355013998229e-1, 1.17980764446305e-1, 1.09431257929842e-1, 9.68312916837090e-2, 8.19531082099494e-2, 6.62795971230357e-2, 5.10192843604564e-2, 3.71053713203179e-2, 2.51931143920290e-2, 1.56624561420511e-2, 8.62924747911945e-3, 3.96638761660894e-3, 1.33491824730003e-3, 2.24207638462937e-4 };
const double Numeric::qd_LOG_w18[18] = { 5.07847569150232e-2, 8.74918217698710e-2, 1.06231987072427e-1, 1.13600962803119e-1, 1.12940421014858e-1, 1.06540929054561e-1, 9.62078032569690e-2, 8.34492524143092e-2, 6.95422794922013e-2, 5.55525077526928e-2, 4.23366797199512e-2, 3.05405451343943e-2, 2.05983704127194e-2, 1.27372513543855e-2, 6.98775937952583e-3, 3.20143571140962e-3, 1.07495526563557e-3, 1.80281475947801e-4 };
const double Numeric::qd_LOG_w19[19] = { 4.67193525156959e-2, 8.10871117350897e-2, 9.93176888151342e-2, 1.07306686287853e-1, 1.07993224036674e-1, 1.03360703222194e-1, 9.49578478153139e-2, 8.40770856575388e-2, 7.18209287678724e-2, 5.91249841059563e-2, 4.67634017963781e-2, 3.53481401173877e-2, 2.53276486089719e-2, 1.69879052239090e-2, 1.04573449694563e-2, 5.71638941331142e-3, 2.61174087234964e-3, 8.75215444108251e-4, 1.46600594806024e-4 };
const double Numeric::qd_LOG_w20[20] = { 4.31427521332081e-2, 7.53837099085894e-2, 9.30532674516631e-2, 1.01456711849830e-1, 1.03201762056072e-1, 1.00022549805273e-1, 9.32597993002977e-2, 8.40289528719411e-2, 7.32855891300307e-2, 6.18503369137303e-2, 5.04166044383747e-2, 3.95513700052984e-2, 2.96940778958128e-2, 2.11563153554271e-2, 1.41237329389640e-2, 8.66097450433550e-3, 4.71994014620360e-3, 2.15139740396521e-3, 7.19728214653203e-4, 1.20427676330217e-4 };
