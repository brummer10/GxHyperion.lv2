// generated from file './/hyper.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace hyper {

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	class SIG0 {
	  private:
		int 	fSamplingFreq;
		static double 	fWave0[100];
		int 	idxfWave0;
	  public:
		int getNumInputs() 	{ return 0; }
		int getNumOutputs() 	{ return 1; }
		void init(int samplingFreq) {
			fSamplingFreq = samplingFreq;
			idxfWave0 = 0;
		}
		void fill (int count, double output[]) {
			for (int i=0; i<count; i++) {
				output[i] = fWave0[idxfWave0];
				// post processing
				idxfWave0 = (idxfWave0 + 1) % 100;
			}
		}
	};
			FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	double 	fRec0[2];
	double 	fConst0;
	double 	fConst1;
	double 	fConst2;
	double 	fConst3;
	double 	fConst4;
	double 	fConst5;
	double 	fConst6;
	double 	fConst7;
	double 	fConst8;
	double 	fConst9;
	double 	fConst10;
	double 	fConst11;
	double 	fConst12;
	double 	fConst13;
	double 	fConst14;
	double 	fConst15;
	double 	fRec1[5];
	double 	fConst16;
	double 	fConst17;
	double 	fConst18;
	double 	fConst19;
	double 	fConst20;
	static double 	ftbl0[100];
	FAUSTFLOAT 	fsliderV0;
	FAUSTFLOAT 	*fsliderV0_;
	double 	fRecV0[2];
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};


double Dsp::ftbl0[100];

Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "hyper";
	name = N_("Hyperion");
	mono_audio = compute_static;
	stereo_audio = 0;
	set_samplerate = init_static;
	activate_plugin = 0;
	connect_ports = connect_static;
	clear_state = clear_state_f_static;
	delete_instance = del_instance;
}

Dsp::~Dsp() {
}

inline void Dsp::clear_state_f()
{
	for (int i=0; i<2; i++) fRec0[i] = 0;
	for (int i=0; i<5; i++) fRec1[i] = 0;
	for (int i=0; i<2; i++) fRecV0[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	SIG0 sig0;
	sig0.init(samplingFreq);
	sig0.fill(100,ftbl0);
	fSamplingFreq = samplingFreq;
	fConst0 = double(min(192000, max(1, fSamplingFreq)));
	fConst1 = (2.92152936408456e-19 * fConst0);
	fConst2 = (6.73749185170656e-12 + (fConst0 * (1.5935372963158e-13 + (fConst0 * (5.03409852468555e-16 + fConst1)))));
	fConst3 = (3.57235773126228e-20 * fConst0);
	fConst4 = (8.42399944296991e-12 + (fConst0 * (3.65710504438694e-14 + (fConst0 * (6.1711306334176e-17 + fConst3)))));
	fConst5 = ((fConst0 * (1.5935372963158e-13 + (fConst0 * (fConst1 - 5.03409852468555e-16)))) - 6.73749185170656e-12);
	fConst6 = ((fConst0 * (3.65710504438694e-14 + (fConst0 * (fConst3 - 6.1711306334176e-17)))) - 8.42399944296991e-12);
	fConst7 = (1.16861174563382e-18 * fConst0);
	fConst8 = faustpower<2>(fConst0);
	fConst9 = ((fConst8 * (1.00681970493711e-15 - fConst7)) - 1.34749837034131e-11);
	fConst10 = (1.42894309250491e-19 * fConst0);
	fConst11 = ((fConst8 * (1.23422612668352e-16 - fConst10)) - 1.68479988859398e-11);
	fConst12 = ((1.75291761845074e-18 * fConst8) - 3.1870745926316e-13);
	fConst13 = ((2.14341463875737e-19 * fConst8) - 7.31421008877389e-14);
	fConst14 = (1.34749837034131e-11 + (fConst8 * (0 - (1.00681970493711e-15 + fConst7))));
	fConst15 = (1.68479988859398e-11 + (fConst8 * (0 - (1.23422612668352e-16 + fConst10))));
	fConst16 = faustpower<3>(fConst0);
	fConst17 = (2.13713705917997e-14 * fConst16);
	fConst18 = (0 - fConst17);
	fConst19 = (4.27427411835994e-14 * fConst16);
	fConst20 = (0 - fConst19);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fsliderV0 (*fsliderV0_)
	double 	fSlowV0 = (0.0010000000000000009 * double(fsliderV0));

	double 	fSlow0 = (0.007000000000000006 * (1 - double(fslider0)));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993 * fRec0[1]) + fSlow0);
		double fTemp0 = (3.36874592585328e-10 + (fConst0 * (fConst4 + (fConst2 * fRec0[0]))));
		fRec1[0] = ((double)input0[i] - (((((fRec1[1] * (1.34749837034131e-09 + (fConst0 * (fConst15 + (fConst14 * fRec0[0]))))) + (fRec1[2] * (2.02124755551197e-09 + (fConst8 * (fConst13 + (fConst12 * fRec0[0])))))) + (fRec1[3] * (1.34749837034131e-09 + (fConst0 * (fConst11 + (fConst9 * fRec0[0])))))) + (fRec1[4] * (3.36874592585328e-10 + (fConst0 * (fConst6 + (fConst5 * fRec0[0])))))) / fTemp0));
		double fTemp1 = (((((fConst20 * fRec1[1]) + (fConst17 * fRec1[0])) + (fConst19 * fRec1[3])) + (fConst18 * fRec1[4])) / fTemp0);
		double fTemp2 = fabs(fTemp1);
		double fTemp3 = (101.97 * (fTemp2 / (3.0 + fTemp2)));
		double fTemp4 = max((double)0, min((double)99, floor(fTemp3)));
		double fTemp5 = ((int((0 < fTemp4)))?0:((int((fTemp4 < 99)))?(fTemp3 - fTemp4):99));
		output0[i] = (FAUSTFLOAT)(fabs(((ftbl0[int(fTemp4)] * (1 - fTemp5)) + (fTemp5 * ftbl0[int((1 + fTemp4))]))) * ((int(((fTemp2 * ((int((fTemp1 < 0)))?1:-1)) < 0)))?-1:1));
		// post processing
		for (int i=4; i>0; i--) fRec1[i] = fRec1[i-1];
		fRec0[1] = fRec0[0];
	}
	for (int i=0; i<count; i++) {
		fRecV0[0] = ((0.999 * fRecV0[1]) + fSlowV0);
		output0[i] = (FAUSTFLOAT)((double)output0[i] * fRecV0[0]);
		// post processing
		fRecV0[1] = fRecV0[0];
	}

#undef fsliderV0 
#undef fslider0
}
	
	
	double 	Dsp::SIG0::fWave0[100] = {
	0.0,0.0252525303042,0.0505050554952,0.0757575805852,0.101010105408,
	0.126262629527,0.151515151785,0.176767669127,0.202020173487,0.227272643558,
	0.252525023071,0.27777716344,0.30302867248,0.328278516174,0.353523976201,
	0.378757960762,0.403962331699,0.429092973801,0.454054762955,0.478689455764,
	0.502836733588,0.526445276195,0.549584906934,0.572366805873,0.594888006261,
	0.617219241416,0.639409501226,0.661492650438,0.683492486112,0.705426107436,
	0.727306087679,0.749141876788,0.770940721036,0.792708278216,0.814449037946,
	0.836166614854,0.857863957123,0.879543497557,0.90120726487,0.922856966935,
	0.944494053967,0.966119767075,0.98773517605,1.00934120908,1.03093867636,
	1.05252828904,1.07411067455,1.09568638907,1.11725592785,1.13881973368,
	1.16037820399,1.18193169674,1.20348053549,1.22502501359,1.24656539782,
	1.26810193145,1.28963483693,1.31116431816,1.3326905625,1.35421374248,
	1.37573401732,1.39725153427,1.41876642975,1.44027883039,1.46178885393,
	1.48329661007,1.5048022011,1.52630572263,1.5478072641,1.56930690934,
	1.59080473699,1.61230082094,1.63379523069,1.65528803169,1.67677928567,
	1.69826905088,1.71975738237,1.74124433221,1.7627299497,1.78421428156,
	1.80569737213,1.82717926349,1.84865999562,1.87013960657,1.89161813255,
	1.91309560803,1.9345720659,1.95604753753,1.97752205287,1.99899564052,
	2.02046832719,2.04193999607,2.06337932704,2.08170426416,2.08860470934,
	2.09152655523,2.09332986318,2.09463709766,2.0956676926,2.09652273038
	};

void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case INTENSITY: 
		fslider0_ = (float*)data; // , 0.5, 0.0, 1.0, 0.01 
		break;
	case VOLUME: 
		fsliderV0_ = (float*)data; // , 0.5, 0.0, 1, 0.01 
		break;
	default:
		break;
	}
}

void Dsp::connect_static(uint32_t port,void* data, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->connect(port, data);
}


PluginLV2 *plugin() {
	return new Dsp();
}

void Dsp::del_instance(PluginLV2 *p)
{
	delete static_cast<Dsp*>(p);
}

/*
typedef enum
{
   INTENSITY, 
   VOLUME,
} PortIndex;
*/

} // end namespace hyper
