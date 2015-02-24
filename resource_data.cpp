#include "resource.h"

Resource_datum* Resource_data [RES_MAX];
Crop_datum*     Crop_data     [CROP_MAX];
Mineral_datum*  Mineral_data  [MINERAL_MAX];

// RESOURCE MACROS
#define _resource(n) \
  cur_id = (n)
#define _rname(s) \
  Resource_data[cur_id]->name = (s)
#define _rcolor(c) \
  Resource_data[cur_id]->color = (c)
#define _luxury(t) \
  Resource_data[cur_id]->luxury_type = (t)
#define _demand(n) \
  Resource_data[cur_id]->demand = (n)
#define _morale(n) \
  Resource_data[cur_id]->morale = (n)
#define _meta() \
  Resource_data[cur_id]->meta = true

// CROP MACROS
#define _crop(n) \
  cur_id = (n)
#define _cname(s) \
  Crop_data[cur_id]->name = (s)
// percentage is the frequency of placement; what % of terrain should it cover
#define _cpercent(s) \
  Crop_data[cur_id]->percentage = (s)
#define _food(s) \
  Crop_data[cur_id]->food = (s)
#define _bonus(t, a) \
  Crop_data[cur_id]->bonus_resources.push_back( Resource_amount ( (t), (a) ) )
#define _type(s) \
  Crop_data[cur_id]->type = (s)

// MINERAL MACROS
#define _mineral(n) \
  cur_id = (n)
#define _mpercent(s) \
  Mineral_data[cur_id]->percentage = (s)
#define _mvalue(s) \
  Mineral_data[cur_id]->value = (s)
#define _mname(s) \
  Mineral_data[cur_id]->name = (s)
#define _mcolor(c) \
  Mineral_data[cur_id]->color = (c)
#define _mhidden() \
  Mineral_data[cur_id]->hidden = true


void init_resource_data()
{
  for (int i = 0; i < RES_MAX; i++) {
    Resource_data[i] = new Resource_datum();
  }
  for (int i = 0; i < CROP_MAX; i++) {
    Crop_data[i] = new Crop_datum();
  }
  for (int i = 0; i < MINERAL_MAX; i++) {
    Mineral_data[i] = new Mineral_datum();
  }


  int cur_id = 0;

  _resource(RES_NULL);
    _rname("any resource");
    _rcolor(c_dkgray);

  _resource(RES_GOLD);
    _rname("gold");
    _rcolor(c_yellow);

  _resource(RES_FOOD);
    _rname("food");
    _rcolor(c_green);

  _resource(RES_WOOD);
    _rname("wood");
    _rcolor(c_ltred);

  _resource(RES_STONE);
    _rname("stone");
    _rcolor(c_ltgray);

  _resource(RES_FIBER);
    _rname("fiber");
    _rcolor(c_ltgray);

  _resource(RES_FUR);
    _rname("fur");
    _rcolor(c_brown);

  _resource(RES_LEATHER);
    _rname("leather");
    _rcolor(c_brown);

  _resource(RES_UNICORN_HORN);
    _rname("unicorn horn");
    _rcolor(c_pink);

  _resource(RES_SALT);
    _rname("salt");
    _rcolor(c_white);
    _luxury(LUX_NULL);  // Salt's technical a spice, but it's universally wanted
    _demand(100);
    _morale(6);

  _resource(RES_PEPPER);
    _rname("pepper");
    _rcolor(c_dkgray);
    _luxury(LUX_SPICE);
    _demand(80);
    _morale(5);

  _resource(RES_CINNAMON);
    _rname("cinnamon");
    _rcolor(c_brown);
    _luxury(LUX_SPICE);
    _demand(40);
    _morale(3);

  _resource(RES_TOBACCO);
    _rname("tobacco");
    _rcolor(c_brown);
    _luxury(LUX_SMOKABLE);
    _demand(75);
    _morale(5);

  _resource(RES_CANNABIS);
    _rname("cannabis");
    _rcolor(c_green);
    _luxury(LUX_SMOKABLE);
    _demand(40);
    _morale(5);

  _resource(RES_AMANITAS);
    _rname("amanitas");
    _rcolor(c_magenta);
    _luxury(LUX_HALLUCINOGEN);
    _demand(5);
    _morale(3);

  _resource(RES_AYAHUASCA);
    _rname("ayahuasca");
    _rcolor(c_magenta);
    _luxury(LUX_HALLUCINOGEN);
    _demand(4);
    _morale(3);

  _resource(RES_SPICEREED);
    _rname("spicereed");
    _rcolor(c_magenta);
    _luxury(LUX_HALLUCINOGEN);
    _demand(30);
    _morale(4);

  _resource(RES_CLOTHING);
    _rname("clothing");
    _rcolor(c_white);
    _demand(15);
    _morale(10);

  _resource(RES_FUR_COATS);
    _rname("fur coats");
    _rcolor(c_brown);
    _luxury(LUX_COATS);
    _demand(10);
    _morale(5);

  _resource(RES_LEATHER_COATS);
    _rname("leather coats");
    _rcolor(c_brown);
    _luxury(LUX_COATS);
    _demand(10);
    _morale(5);

  _resource(RES_WOOD_HOUSEWARES);
    _rname("wood housewares");
    _rcolor(c_ltred);
    _luxury(LUX_HOUSEWARES);
    _demand(10);
    _morale(5);

  _resource(RES_TIN_HOUSEWARES);
    _rname("tin housewares");
    _rcolor(c_ltcyan);
    _luxury(LUX_HOUSEWARES);
    _demand(10);
    _morale(6);

  _resource(RES_COPPER_HOUSEWARES);
    _rname("copper housewares");
    _rcolor(c_ltred);
    _luxury(LUX_HOUSEWARES);
    _demand(10);
    _morale(7);

  _resource(RES_IRON_HOUSEWARES);
    _rname("iron housewares");
    _rcolor(c_cyan);
    _luxury(LUX_HOUSEWARES);
    _demand(10);
    _morale(8);

  _resource(RES_FURNITURE);
    _rname("furniture");
    _rcolor(c_ltred);
    _demand(8);
    _morale(10);

  _resource(RES_JEWELRY);
    _rname("jewelry");
    _rcolor(c_magenta);
    _demand(5);
    _morale(15);

  _resource(RES_FARMING);
    _rname("farming");
    _rcolor(c_magenta);
    _meta();

  _resource(RES_MINING);
    _rname("mining");
    _rcolor(c_magenta);
    _meta();

  _resource(RES_HUNTING);
    _rname("hunting");
    _rcolor(c_magenta);
    _meta();

  _resource(RES_LOGGING);
    _rname("logging");
    _rcolor(c_magenta);
    _meta();

// _food() is per 100 units of the crop!
  _crop(CROP_NULL);
    _cname("any crop");

  _crop(CROP_WHEAT);
    _cname("wheat");
    _cpercent(90);
    _type(CROPTYPE_FOOD);
    _food(100);

  _crop(CROP_CABBAGE);
    _cname("cabbage");
    _cpercent(70);
    _type(CROPTYPE_FOOD);
    _food(120);

  _crop(CROP_GRAPES);
    _cname("grapes");
    _cpercent(30);
    _type(CROPTYPE_FOOD);
    _food(50);

  _crop(CROP_MELON);
    _cname("melon");
    _cpercent(40);
    _type(CROPTYPE_FOOD);
    _food(80);

  _crop(CROP_RICE);
    _cname("rice");
    _cpercent(90);
    _type(CROPTYPE_FOOD);
    _food(110);

  _crop(CROP_CACTUS);
    _cname("cactus");
    _cpercent(90);
    _type(CROPTYPE_FOOD);
    _food(60);

  _crop(CROP_PEPPER);
    _cname("pepper");
    _cpercent(60);
    _type(CROPTYPE_SPICE);
    _food(15);
    _bonus(RES_PEPPER, 90);

  _crop(CROP_CINNAMON);
    _cname("cinnamon");
    _cpercent(40);
    _type(CROPTYPE_SPICE);
    _bonus(RES_CINNAMON, 100);

  _crop(CROP_TOBACCO);
    _cname("tobacco");
    _cpercent(30);
    _type(CROPTYPE_DRUG);
    _bonus(RES_TOBACCO, 100);

  _crop(CROP_AMANITAS);
    _cname("amanitas");
    _cpercent(10);
    _type(CROPTYPE_DRUG);
    _bonus(RES_AMANITAS, 100);

  _crop(CROP_AYAHUASCA);
    _cname("ayahuasca");
    _cpercent(10);
    _type(CROPTYPE_DRUG);
    _bonus(RES_AYAHUASCA, 100);

  _crop(CROP_SPICEREED);
    _cname("spicereed");
    _cpercent(8);
    _type(CROPTYPE_DRUG);
    _bonus(RES_SPICEREED, 100);

  _crop(CROP_DEATHCAP);
    _cname("deathcap");
    _cpercent(7);
    _type(CROPTYPE_POISON);

  _crop(CROP_VIPERVINE);
    _cname("vipervine");
    _cpercent(10);
    _type(CROPTYPE_POISON);

  _crop(CROP_SCORPICON);
    _cname("scorpicon");
    _cpercent(7);
    _type(CROPTYPE_POISON);

  _crop(CROP_COTTON);
    _cname("cotton");
    _cpercent(70);
    _type(CROPTYPE_FIBER);
    _bonus(RES_FIBER, 100);

  _crop(CROP_HEMP);
    _cname("hemp");
    _cpercent(60);
    _type(CROPTYPE_FIBER);
    _bonus(RES_FIBER, 80);
    _bonus(RES_CANNABIS, 20);

// Minerals

  _mineral(MINERAL_NULL);
    _mname("any mineral");
    _mcolor(c_dkgray);

  _mineral(MINERAL_STONE);
    _mname("stone");
    _mpercent(98);
    _mvalue(1);
    _mcolor(c_white);

  _mineral(MINERAL_TIN);
    _mname("tin");
    _mpercent(70);
    _mvalue(5);
    _mcolor(c_ltcyan);
    _mhidden();

  _mineral(MINERAL_COPPER);
    _mname("copper");
    _mpercent(50);
    _mvalue(20);
    _mcolor(c_ltred);
    _mhidden();

  _mineral(MINERAL_IRON);
    _mname("iron");
    _mpercent(70);
    _mvalue(25);
    _mcolor(c_cyan);
    _mhidden();

  _mineral(MINERAL_SALT);
    _mname("salt");
    _mpercent(50);
    _mvalue(18);
    _mcolor(c_white);
    _mhidden();

  _mineral(MINERAL_GEMS);
    _mname("gems");
    _mpercent(3);
    _mvalue(100);
    _mcolor(c_pink);
    _mhidden();

// The value of gold is less than 100 because it takes labor and fuel to
// convert it into spendable currency!
  _mineral(MINERAL_GOLD);
    _mname("gold");
    _mpercent(4);
    _mvalue(80);
    _mcolor(c_yellow);
    _mhidden();

  _mineral(MINERAL_COAL);
    _mname("coal");
    _mpercent(20);
    _mvalue(50);
    _mcolor(c_dkgray);
    _mhidden();
}
