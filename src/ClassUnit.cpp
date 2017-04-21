#include "GlobalFunctionMissiom.h"

using namespace std;
using namespace sf;

Unit * Unit::NIL = new Unit();

Unit::Unit(float X, float Y, float W, float H, int i, int j, int id, int _fa, string L, int _U, string _C)		//�������� �����
{
	UnitToUnit = _U;
	anspeed = 0.006;		//0.006
	speed = 0.0004;

	pos = new Vector2f(i, j);

	CurrentFrameToAttackReceiving = 0;
	CurrentFrame = 0;

	Test = Generation_Rand_name();

	Id = id;

	lvl = 1;

	ClassUnit = _C;

	isMove = false;
	isSelect = false;
	isSelectHostile = false;

	_Attack = false;
	ReceivingCutting = false;
	ReceivingPricking = false;
	hurt = false;
	Receiving_int = 0;

	calculation_distance_Attack = 0;
	calculation_distance_x_Attack = 0;
	calculation_distance_y_Attack = 0;

	calculation_distance_x_Step = 0;
	calculation_distance_y_Step = 0;
	calculation_distance_Step = 0;

	Pricking = false;
	Cutting = true;

	_Land = L;
	if (UnitToUnit == 0)
	{
		faction_choice = _fa;
		Sprite_X = W;
		Sprite_Y = H;
		
		w = W; h = H;

		Graphic * g = new Graphic(*pos, SpriteLoader::sprt->halberdier, Vector2i(0, 0), Vector2i(W, H)); //TODO: ������� ����� ������� �� ����� �����������
		if (faction_choice == 0) {}
		if (faction_choice == 1) { 
			delete g;  
			g = new Graphic(*pos, SpriteLoader::sprt->halberdierGray, Vector2i(0, 0), Vector2i(W, H)); 
		}

		animation = new AnimExtended(*g, *(new Animator(projectPath + unitsFolder + "Halberdier/")));
		animation->anSpeed = this->anspeed;

		x = X - w;
		y = Y - h;


		/////////////////////////////�������� ����
		PeopleLive = 100;
		PeopleHealth = 100;

		step = 1.5;
		const_step = 1.5;
		fast_step = 2;

		ConstPeopleLive = 100;
		ConstPeopleHealth = 100;

		Hp = 15;
		HpHurt = 15;

		Morale = 1400;
		Stamina = 1500;

		ConstMorale = Morale;
		ConstStamina = Stamina;
		
		Attack = 5;
		Defense = 2.5;
		Life = true;
		radius = 1.5;

		Ammo = 0;

		CouterAttack = 2;
		ConstCouterAttack = 2;

		fast_step_True = false;

		CouterStep = 2;
		ConstCouterStep = 2;
	}
}

void Unit::To_Move(Mission &TeampMision, float time)				//������� ��������,
{
	distance = sqrt(pow(moveTo.x - pos->x,2) + pow(moveTo.y-pos->y,2));//������� ��������� (���������� �� ����� � �� ����� �). ��������� ������� ����� �������
	if (distance > 0.002)//���� �������� ������� �������� �� ����� �������� ������� �������
	{
		isSelect = false;

		if (animation->ar->getCurrentAnim() != "move") { animation->ar->setAnim("move"); }

		pos->x += (speed*time*(moveTo.x - pos->x) / distance);//���� �� ���� � ������� ������� �������
		pos->y += (speed*time*(moveTo.y - pos->y) / distance);//���� �� ������ ��� ��

	}
	else 
	{ 
		isMove = false; 
		/*std::cout << "priehali\n" << endl;  cout << "i:" << _I << " j:" << _J << endl; cout << "Stamina:" << Stamina << endl;*/ 
		animation->ar->setAnim("idle");
		pos->x = moveTo.x;
		pos->y = moveTo.y;
	}//������� ��� ��� ������ �� ���� 
}

void Unit::AttackToAttack(Unit & _gets_lyuley, float time)
{
	gets_lyuley = &_gets_lyuley;
	int minStaminaDrain, maxStaminaDrain, staminaDrain;

	minStaminaDrain = 50;		
	maxStaminaDrain = 90;
	staminaDrain = minStaminaDrain + rand() % (maxStaminaDrain - minStaminaDrain);
	Stamina -= staminaDrain;	//���������� ������������

	animation->ar->setAnim("attack");
	_Attack = true;				//������ ���������
}

void Unit::damageTarget() {
	int AllHp, AllHpKill, min_attack_, max_attack_, _attack_, AllDefeat, min_percent, max_percent, GeneratePercent;

	min_attack_ = (Attack * (PeopleHealth / 2)) + ((PeopleLive - PeopleHealth) * (Attack / 2));						//����� ��� �����
	max_attack_ = ((Attack * PeopleHealth) + (PeopleLive - PeopleHealth) * (Attack / 2));							//����� ���� �����

	min_percent = 5;	//�������� ������
	max_percent = 20;

	AllHp = gets_lyuley->HpHurt * gets_lyuley->PeopleHealth;		//����������� �� �� �������
	AllHpKill = gets_lyuley->Hp * gets_lyuley->PeopleLive;		//����������� ���� � ������
	AllDefeat = gets_lyuley->PeopleHealth * gets_lyuley->Defense;	//����������� ������, ������ ����� ������ �� �������

	_attack_ = min_attack_ + rand() % (max_attack_ - min_attack_);			//������������
	GeneratePercent = min_percent + rand() % (max_percent - min_percent);

	AllHpKill = AllHpKill - ((_attack_ / 100) * GeneratePercent);	//������� ����������� ���� ������

	if (gets_lyuley->PeopleHealth > 0)
	{
		AllHp = AllHp - (_attack_ - AllDefeat);				//���� ��� �������
		gets_lyuley->PeopleHealth = AllHp / gets_lyuley->HpHurt;
	}
	else { gets_lyuley->PeopleHealth = 0; AllHpKill = AllHpKill - ((_attack_ / 100) * GeneratePercent); }
	gets_lyuley->PeopleLive = AllHpKill / gets_lyuley->Hp;

	if (gets_lyuley->PeopleLive < gets_lyuley->PeopleHealth)
	{
		gets_lyuley->PeopleHealth = 0;
		gets_lyuley->PeopleHealth = gets_lyuley->PeopleLive;
	}
	/*cout << "������� � ������:" << gets_lyuley->PeopleLive << endl;
	cout << "������� � ������ �� �������:" << gets_lyuley->PeopleHealth << endl;*/
	if (gets_lyuley->PeopleHealth > 0) { /*cout << "��������:" << gets_lyuley->PeopleLive - gets_lyuley->PeopleHealth << endl;*/ }
	else { /*cout << "��������:" << gets_lyuley->PeopleLive << endl;*/ gets_lyuley->PeopleHealth = 0; }
	cout << Stamina << endl;

	if (Cutting == true) { gets_lyuley->ReceivingCutting = true; }
	if (Pricking == true) { gets_lyuley->ReceivingPricking = true; }
	gets_lyuley = nullptr;
}

void Unit::AnimationToAttack(float time)
{
	if (_Attack == true)
	{
		if (animation->ar->isPastPeak()) {
			_Attack = false;
			damageTarget();
		}
	}
}

void Unit::ReceivingFace(float time)
{
	if (ReceivingCutting == true)
	{
		animation->ar->setAnim("slashed");
		animation->ar->setVariant("slashSide", !animation->ar->getVariantState("slashSide"));
		ReceivingCutting = false;
	}
	if (ReceivingPricking == true)
	{
		animation->ar->setAnim("poked");
		ReceivingPricking = false;
	}
	if (PeopleHealth <= 0 && !hurt)
	{
		hurt = true;
		animation->ar->setVariant("wounded", true);
	}
	if (PeopleLive <= 0 && Life == true && animation->ar->isPastPeak())
	{
		Life = false;
		//cout << "�����, ���������!" << endl;
		Graphic * g= new Graphic(*pos, SpriteLoader::sprt->halberdier, Vector2i(128, 0), animation->dim);
		if (faction_choice == 0) {}
		if (faction_choice == 1) {
			delete g;
			g = new Graphic(*pos, SpriteLoader::sprt->halberdierGray, Vector2i(128, 0), animation->dim);
		}
		delete animation;
		animation = g;
	}
}

void Unit::Update(Mission &TeampMision, float time)		//������� ������ �����
{
	if (Life) {
		if (isMove == true) { To_Move(TeampMision, time); }
		if (fast_step_True == true) { step = fast_step; }
		if (fast_step_True == false) { step = const_step; }

		AnimationToAttack(time);
		ReceivingFace(time);
	}
}

void Unit::Halt()
{
	int min_Halt, max_Halt, SummStamina;
	min_Halt = 10;
	max_Halt = 100;

	SummStamina = min_Halt + rand() % (max_Halt - min_Halt);

	/*cout << "________" << endl;
	cout << "SummStamina" << SummStamina << endl;
	cout << "Summ" << Stamina << endl;
	Stamina += SummStamina;*/
	if (Stamina > ConstStamina)
	{
		Stamina = ConstStamina;
	}
	/*cout << "Summ+" << Stamina << endl;
	cout << "________" << endl;*/

	CouterAttack = 0;
	CouterStep = 0;
}

void Unit::drawTo(RenderWindow & window, float time) { animation->drawTo(window, time); }