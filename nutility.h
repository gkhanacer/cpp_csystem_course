#ifndef NUTILITY_H
#define NUTILITY_H

#include <random>
#include <string>
#include <ostream>
#include <forward_list>
#include <algorithm>
#include <ctime>

[[nodiscard]] constexpr int ndigit(int val)
{
	if (val == 0)
		return 1;

	int digit_count{};
	while (val != 0) {
		val /= 10;
		++digit_count;
	}

	return digit_count;
}

////////////////////////////////////////////////////////////

template <typename T>
[[nodiscard]] constexpr bool isprime(T val)
{
	if (val < 2)
		return false;

	if (val % 2 == 0)
		return val == 2;

	if (val % 3 == 0)
		return val == 3;

	if (val % 5 == 0)
		return val == 5;

	for (int k = 7; k * k <= val; k += 2)
		if (val % k == 0)
			return false;

	return true;
}

////////////////////////////////////////////////////////////

[[nodiscard]] inline std::ranlux48_base& urng()
{
	static std::ranlux48_base eng{ std::random_device{}() };

	return eng;
};

////////////////////////////////////////////////////////////

template<typename T>
class Rand {
public:
	Rand() = default;
	Rand(T min, T max) : m_dist{ min, max } {}
	auto operator()()
	{
		return m_dist(urng());
	}
private:
	std::uniform_int_distribution<T> m_dist;
};

////////////////////////////////////////////////////////////

inline void randomize()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
}

////////////////////////////////////////////////////////////

[[nodiscard]] inline std::string rname()
{
	static const char* const pnames[] = {
"abdi", "abdullah", "abdulmuttalip", "adem", "adnan", "afacan", "agah", "ahmet", "akin", "alev",
"ali", "alican", "alparslan", "anil", "arda", "asim", "askin", "aslican", "aslihan", "ata",
"atakan", "atalay", "atif", "atil", "aycan", "aydan", "aykut", "ayla", "aylin", "aynur",
"ayse", "aytac", "aziz", "azize", "azmi", "baran", "bekir", "belgin", "bennur", "beril",
"berivan", "berk", "beste", "beyhan", "bilal", "bilge", "bilgin", "billur", "binnaz", "binnur",
"birhan", "bora", "bulent", "burak", "burhan", "busra", "cahide", "cahit", "can", "canan",
"candan", "caner", "cansu", "cebrail", "celal", "celik", "cem", "cemal", "cemil", "cemile",
"cemre", "cengiz", "cesim", "cetin", "ceyda", "ceyhan", "ceyhun", "ceylan", "cezmi", "cihan",
"cihat", "ciler","cumhur", "cuneyt", "demet", "demir", "deniz", "derin", "derya", "devlet", "devrim", "diana",
"dilber", "dilek", "dogan", "dost", "durmus", "durriye", "ece", "eda", "edip", "ediz",
"efe", "efecan", "ege", "egemen", "emine", "emirhan", "emre", "emrecan", "enes", "engin",
"ercument", "erdem", "esen", "esin", "esra", "eylul", "fadime", "fahri", "fazilet", "feramuz",
"feraye", "ferhat", "ferhunde", "figen", "fikret", "fuat", "fugen", "furkan", "galip", "garo",
"gazi", "gizem", "gul", "gulden", "gulsah", "gulsen", "gunay", "gurbuz", "gursel", "hakan",
"hakki", "haldun", "halime", "haluk", "handan", "hande", "handesu", "hasan", "helin", "hikmet",
"hilal", "hilmi", "hulki", "hulusi", "hulya", "huseyin", "iffet", "irmak", "ismail", "izzet",
"jade", "julide", "kaan", "kamil", "kamile", "kasim", "kaya", "kayahan", "kayhan", "kazim",
"kelami", "kenan", "kerem", "kerim", "keriman", "kezban", "korhan", "kunter", "kurthan", "lale",
"lamia", "leyla", "mahir", "malik", "mehmet", "melek", "melih", "melike", "melisa", "menekse", "mert",
"metin", "nucahit", "muhsin", "mukerrem", "murat", "murathan", "muruvvet", "muslum", "mustafa", "muzaffer", "naci", "naciye",
"nagehan", "nahit", "nalan", "nasrullah", "naz", "nazif", "nazife", "nazli", "necmettin", "necmi",
"necmiye", "nedim", "nefes", "nevsin", "nihal", "nihat", "nisan", "niyazi", "nurdan", "nuri",
"nuriye", "nurullah", "nusret", "okan", "olcay", "onat", "orkun", "osman", "pakize", "papatya",
"pelin", "pelinsu", "perihan", "petek", "pinat", "polat", "polathan", "poyraz", "recep", "refik",
"refika", "rumeysa", "rupen", "saadet", "sabriye", "sade", "sadegul", "sadettin", "sadi", "sadiye",
"sadri", "sadullah", "samet", "sami", "saniye", "sarp", "sefa", "sefer", "selenay", "selin",
"semsit", "sevda", "sevilay", "sevim", "seyhan", "sezai", "sezen", "sezer", "sidre", "sinem",
"soner", "su", "suheyla", "suleyman", "sumeyye", "suphi", "taci", "taner", "tanju", "tansel",
"tansu", "tarcan", "tarik", "tarkan", "tayfun", "tayyar", "tayyip", "tekin", "temel", "teoman",
"teslime", "tevfik", "tijen", "tonguc", "tufan", "tugay", "tugra", "tunc", "tuncer", "turgut",
"turhan", "ufuk", "ugur", "umit", "utku", "yalcin", "yasar", "yasemin", "yasin",
"yavuz", "yelda", "yeliz", "yesim", "yilmaz", "yunus", "yurdagul", "yurdakul", "yurdanur", "yusuf",
"zahide", "zahit", "zarife", "zekai", "necati", "zeliha", "zerrin", "ziya", "zubeyde", };

	return pnames[Rand(0, static_cast<int>(std::size(pnames) - 1))()];
}

////////////////////////////////////////////////////////////

[[nodiscard]] inline std::string rfname()
{
	static const char* const pfnames[] = {
	"acar", "acgoze", "acuka", "ademoglu", "adiguzel", "agaoglu", "akarsu", "akcalar", "akgunes", "akkay",
	"akkuyu", "aklikit", "aksakal", "akyildiz", "akyoldas", "alemdar", "alniacik", "altindag", "altinisik", "altinorak",
	"arcan", "aslan", "avci", "aybeyaz", "aylak", "azmak", "bahceli", "bakirci", "baklavaci", "barutcu",
	"baturalp", "bayraktar", "bekar", "belgeli", "beyaz", "bilgic", "bozkaya", "boztas", "canbay", "candamar",
	"cangoz", "cankoc", "canlikaya", "cansever", "cansiz", "celik", "celiker", "cengaver", "cevikkol", "cilingir",
	"comakci", "corbaci", "cubukay", "cuhadar", "daglarca", "damar", "degirmenci", "demirdogen", "demirel", "derin",
	"dingin", "dokmeci", "dokuzcan", "dosteli", "dumbuk", "dunyalik", "ecevit", "edepli", "edepsiz", "efelik",
	"elebasi", "eliagir", "elibol", "elitemiz", "elkizi", "elmali", "eloglu", "emirkulu", "engerek", "engereke",
	"erdogan", "ergin", "erim", "ersoy", "ertakan", "esbereli", "esnedur", "esteberli", "etci", "ezergecer",
	"fakir", "fedai", "fincan", "firatonu", "fitrat", "gamsiz", "gedik", "geldik", "gilgamis", "girik",
	"girit", "gucsuz", "gultekin", "gumus", "gurkas", "hamsikoylu", "harmanci", "haselici", "hepguler", "hurmaci",
	"iliksiz", "issiz", "jilet", "kabasakal", "kadersiz", "kahraman", "kalemsiz", "kalinkas", "kalpsiz", "kalpten",
	"kapan", "kapici", "kaplan", "kara", "karabatur", "karaduman", "karaelmas", "karakis", "karakoyun", "karakuzu",
	"karamuk", "karaorman", "karasaban", "karataban", "karayel", "kayabasi", "kazanci", "kecisakal", "kelepce", "kelleci",
	"keskin", "kesman", "kilicdar", "kilimci", "kilinc", "kirboga", "kirci", "kocyigit", "kolcak", "komcu",
	"komurcu", "konak", "konca", "koralp", "korukcu", "kosnuk", "kotek", "koylu", "kucukkaya", "kulaksiz",
	"kurban", "kurtulus", "kusmen", "lalezar", "lokmaci", "lombak", "lufer", "maganda", "malazgirt", "malkaciran",
	"mazgirt", "merdane", "mertek", "merzifon", "mirza", "miskin", "miskinoglu", "muglali", "nazik", "nurtopu",
	"olmez", "oltu", "onaran", "ongun", "ordulu", "orhancan", "ormanci", "ortaca", "osmaneli", "otaci",
	"ovacik", "oztoklu", "ozvezneci", "pakdamar", "pirlanta", "polatkan", "portakal", "poturgeli", "reis", "renacan",
	"resimci", "saferikli", "safkan", "salca", "saldiray", "sallabas", "samanci", "saricakir", "sarikafa", "sarpdemir",
	"savaskan", "sefiloglu", "selercan", "semiz", "sener", "serce", "serinsun", "sessiz", "silahdar", "silifkeli",
	"simsek", "sivri", "sofuoglu", "sonmez", "sonuzun", "soylu", "soysalan", "soyubozuk", "sucu", "sulugoz",
	"supuren", "takes", "tamgun", "tamirci", "tantana", "tarumar", "tekinalp", "tekkaya", "tekkilic", "telek",
	"temiz", "temizel", "temizkalp", "tepecik", "tepsici", "tercan", "terlemez", "tertemiz", "tilki", "tokatci",
	"tombeki", "topatan", "topkapi", "tozkoporan", "tufancan", "tunali", "tuzcu", "tuztas", "ufurukcu", "ugursuz",
	"ulakci", "uluocak", "umutsuz", "unalan", "unalmis", "unkapani", "uraz", "uslu", "uyar", "uzay",
	"uzunadam", "yagizeli", "yanardag", "yanardoner", "yangin", "yaracan", "yaradan", "yarma", "yasayavas", "yasli",
	"yasmak", "yavas", "yavasakan", "yaygara", "yelden", "yeldirme", "yeldirmen", "yersiz", "yikilmaz", "yildirim",
	"yilgin", "yilmaz", "yolyapan", "yorganci", "yorgun", "yosun", "yurdakul", "yurekli", "yurekyakan", "yurtsuz",
	"zaimoglu", "zalim", "zengin", "zebani"
	};

	return pfnames[Rand(0, static_cast<int>(std::size(pfnames)) - 1)()];
}

////////////////////////////////////////////////////////////

[[nodiscard]] inline std::string rtown()
{
	static const char* const ptowns[] = {
"izmir", "afyonkarahisar", "kilis", "bolu", "yalova", "giresun", "tunceli", "manisa", "cankiri", "canakkale",
"mugla", "isparta", "ankara", "kahramanmaras", "nigde", "kirklareli", "artvin", "kirikkale", "bursa", "bingol",
"sirnak", "erzincan", "gaziantep", "bayburt", "tekirdag", "kocaeli", "trabzon", "ardahan", "elazig", "karabuk",
"samsun", "malatya", "aksaray", "van", "kars", "amasya", "kirsehir", "balikesir", "eskisehir", "sanliurfa",
"adiyaman", "mardin", "bilecik", "hakkari", "mus", "kayseri", "agri", "sinop", "istanbul", "mersin",
"aydin", "sivas", "yozgat", "igdir", "sakarya", "burdur", "antalya", "osmaniye", "konya", "tokat",
"zonguldak", "corum", "batman", "adana", "usak", "denizli", "edirne", "karaman", "ordu", "diyarbakir",
"siirt", "kutahya", "bitlis", "bartin", "nevsehir", "rize", "kastamonu", "duzce", "erzurum", "gumushane",
"hatay", };
	return ptowns[Rand(0, static_cast<int>(std::size(ptowns)) - 1)()];
}

////////////////////////////////////////////////////////////

inline std::ostream& dline(std::ostream& os)
{
	return os << "\n-----------------------------------------------------------------------------\n";
}

////////////////////////////////////////////////////////////

class de {
public:
	de(long long x) : mx{ x } {}
	friend std::ostream& operator<<(std::ostream& os, de x)
	{
		auto s = std::to_string(x.mx);
		if (s[0] == '-') {
			os << "-";
			s.erase(0, 1);
		}

		auto len = s.length();
		for (size_t i{}; i < len; ++i) {
			os << s[i];
			auto n = len - 1 - i;
			if (n && (len - 1 - i) % 3 == 0)
				os << '.';
		}
		return os;
	}
private:
	long long mx;
};

////////////////////////////////////////////////////////////

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p)
{
	return os << "[" << p.first << ", " << p.second << "]";
}

////////////////////////////////////////////////////////////

template<typename C, typename F>
void rfill(C& c, size_t n, F frand)
{
	while (c.size() < n)
		c.insert(c.end(), frand());
}

////////////////////////////////////////////////////////////

template<typename T, typename F>
void rfill(std::forward_list<T>& c, size_t n, F frand)
{
	while (n--)
		c.insert_after(c.before_begin(), frand());
}

////////////////////////////////////////////////////////////

template<typename C>
void print(const C& c, std::ostream& os, const char* p = " ")
{
	for (const auto& elem : c)
		os << elem << p;
	os << dline;
}

////////////////////////////////////////////////////////////

template<typename InIter>
void print(InIter beg, InIter end, std::ostream& os, const char* p = " ")
{
	while (beg != end) {
		os << *beg++ << p;
	}
	os << dline;
}

////////////////////////////////////////////////////////////

[[nodiscard]] inline std::string random_word()
{
	std::string s(Rand{ 3, 15 }(), '\0');
	static Rand crand{ 0, 25 };

	std::generate(s.begin(), s.end(), [] {return crand() + 'a'; });
	return s;
}


#endif  //NUTILITY_H