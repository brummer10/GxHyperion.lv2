// generated from file './/hyperion.dsp' by dsp2cc:
// Code generated with Faust 0.9.73 (http://faust.grame.fr)


namespace hyperion {

template <int tab_size>
struct table1d_imp { // 1-dimensional clipping table
    float low;
    float high;
    float istep;
    int size;
    float data[tab_size];
};

static table1d_imp<100> clip __rt_data = {
	0.005,0.795235013262,101.97,100, {
	0.00548195523036,0.016445865691,0.0274097761516,0.0383736866119,0.0493375970718,
	0.060301507531,0.0712654179894,0.0822293284464,0.0931932389016,0.104157149354,
	0.115121059803,0.126084970245,0.13704888068,0.148012791103,0.158976701508,
	0.169940611889,0.180904522235,0.19186843253,0.202832342751,0.213796252866,
	0.224760162828,0.23572407257,0.246687981995,0.257651890962,0.26861579927,
	0.279579706628,0.290543612617,0.301507516632,0.312471417804,0.323435314878,
	0.334399206045,0.3453630887,0.356326959087,0.367290811794,0.378254639021,
	0.389218429528,0.400182167115,0.411145828437,0.422109379849,0.433072772871,
	0.444035937638,0.454998773485,0.465961135365,0.476922814321,0.48788350936,
	0.498842787024,0.509800023297,0.520754320256,0.531704386732,0.542648367922,
	0.55358360312,0.564506283341,0.575410971703,0.586289940184,0.597132269761,
	0.607922663898,0.618639951041,0.629255322196,0.639730493837,0.650016225239,
	0.660051925492,0.669767316942,0.679086989359,0.687937882416,0.696258343947,
	0.704006183628,0.711163121782,0.717734492237,0.723745022743,0.72923269117,
	0.734242606851,0.738822090117,0.743017303269,0.74687127245,0.750422944114,
	0.7537069184,0.756753578753,0.759589425229,0.762237491115,0.764717773458,
	0.767047640962,0.769242202516,0.771314630963,0.773276442704,0.775137736666,
	0.776907397287,0.778593266396,0.780202288563,0.781740634041,0.783213802858,
	0.784626713121,0.785983776084,0.787288960129,0.788545845459,0.789757670968,
	0.790927374556,0.792057627879,0.793150866414,0.794209315546,0.795235013262
	}
};

class Dsp: public PluginLV2 {
private:
	uint32_t fSamplingFreq;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT	*fslider0_;
	float 	fRec0[2];
	float 	fConst0;
	float 	fConst1;
	float 	fConst2;
	float 	fConst3;
	float 	fConst4;
	float 	fConst5;
	float 	fConst6;
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT	*fslider1_;
	float 	fRec2[2];
	float 	fConst7;
	float 	fConst8;
	float 	fConst9;
	float 	fConst10;
	float 	fConst11;
	float 	fConst12;
	float 	fRec3[3];
	float 	fConst13;
	float 	fConst14;
	float 	fRec1[3];
	float 	fConst15;
	void connect(uint32_t port,void* data);
	void clear_state_f();
	void init(uint32_t samplingFreq);
	void compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0);

	static void clear_state_f_static(PluginLV2*);
	static void init_static(uint32_t samplingFreq, PluginLV2*);
	static double symclip(double x);
	static void compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2*);
	static void del_instance(PluginLV2 *p);
	static void connect_static(uint32_t port,void* data, PluginLV2 *p);
public:
	Dsp();
	~Dsp();
};



Dsp::Dsp()
	: PluginLV2() {
	version = PLUGINLV2_VERSION;
	id = "hyperion";
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
	for (int i=0; i<2; i++) fRec2[i] = 0;
	for (int i=0; i<3; i++) fRec3[i] = 0;
	for (int i=0; i<3; i++) fRec1[i] = 0;
}

void Dsp::clear_state_f_static(PluginLV2 *p)
{
	static_cast<Dsp*>(p)->clear_state_f();
}

inline void Dsp::init(uint32_t samplingFreq)
{
	fSamplingFreq = samplingFreq;
	fConst0 = float(min(192000, max(1, fSamplingFreq)));
	fConst1 = (4.31631227745776e-10f * fConst0);
	fConst2 = (4.71363180426802e-06f + (fConst0 * (fConst1 - 1.14936200873509e-07f)));
	fConst3 = faustpower<2>(fConst0);
	fConst4 = (9.42726360853604e-06f - (8.63262455491552e-10f * fConst3));
	fConst5 = (4.71363180426802e-06f + (fConst0 * (1.14936200873509e-07f + fConst1)));
	fConst6 = (1.0f / fConst5);
	fConst7 = (3.23341143501172e-10f * fConst0);
	fConst8 = (1.83849805831403e-06f + fConst7);
	fConst9 = (2.50211258533564e-10f * fConst0);
	fConst10 = (1.41841348393053e-07f + fConst9);
	fConst11 = (fConst7 - 1.83849805831403e-06f);
	fConst12 = (fConst9 - 1.41841348393053e-07f);
	fConst13 = (3.68740376472206e-05f * fConst0);
	fConst14 = (0 - fConst13);
	fConst15 = (fConst3 / fConst5);
	clear_state_f();
}

void Dsp::init_static(uint32_t samplingFreq, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->init(samplingFreq);
}

double always_inline Dsp::symclip(double x) {
    double f = fabs(x);
    f = (f - clip.low) * clip.istep;
    int i = static_cast<int>(f);
    if (i < 0) {
        f = clip.data[0];
    } else if (i >= clip.size-1) {
        f = clip.data[clip.size-1];
    } else {
	f -= i;
	f = clip.data[i]*(1-f) + clip.data[i+1]*f;
    }
    return copysign(f, -x);
}

void always_inline Dsp::compute(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0)
{
#define fslider0 (*fslider0_)
#define fslider1 (*fslider1_)
	float 	fSlow0 = (0.007000000000000006f * float(fslider0));
	float 	fSlow1 = (0.007000000000000006f * (1 - float(fslider1)));
	for (int i=0; i<count; i++) {
		fRec0[0] = ((0.993f * fRec0[1]) + fSlow0);
		float fTemp0 = (0 - (3.59296849789581e-09f * fRec0[0]));
		fRec2[0] = ((0.993f * fRec2[1]) + fSlow1);
		float fTemp1 = (9.19249029157013e-05f + (fConst0 * (fConst10 + (fConst8 * fRec2[0]))));
		fRec3[0] = ((float)input0[i] - (((fRec3[1] * (0.000183849805831403f + (fConst3 * ((0 - (6.46682287002344e-10f * fRec2[0])) - 5.00422517067128e-10f)))) + (fRec3[2] * (9.19249029157013e-05f + (fConst0 * (fConst12 + (fConst11 * fRec2[0])))))) / fTemp1));
		fRec1[0] = ((0.25f * symclip((0.5f * (((fConst14 * fRec3[0]) + (fConst13 * fRec3[2])) / fTemp1)))) - (fConst6 * ((fConst4 * fRec1[1]) + (fConst2 * fRec1[2]))));
		output0[i] = (FAUSTFLOAT)(fConst15 * (((fRec1[0] * fTemp0) + (7.18593699579162e-09f * (fRec0[0] * fRec1[1]))) + (fRec1[2] * fTemp0)));
		// post processing
		fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
		fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
		fRec2[1] = fRec2[0];
		fRec0[1] = fRec0[0];
	}
#undef fslider0
#undef fslider1
}
		
void __rt_func Dsp::compute_static(int count, FAUSTFLOAT *input0, FAUSTFLOAT *output0, PluginLV2 *p)
{
	static_cast<Dsp*>(p)->compute(count, input0, output0);
}


void Dsp::connect(uint32_t port,void* data)
{
	switch ((PortIndex)port)
	{
	case INTENSITY: 
		fslider1_ = (float*)data; // , 0.5f, 0.0f, 1.0f, 0.01f 
		break;
	case VOLUME: 
		fslider0_ = (float*)data; // , 0.5f, 0.0f, 1.0f, 0.01f 
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

} // end namespace hyperion
