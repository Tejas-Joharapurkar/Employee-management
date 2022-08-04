#include <iostream>
using namespace std;
class employee
{
public:
	int id;
	int no_of_projects;
	int apraisal_score;
	string name;
	double salary;

	employee()
	{
		this->id = id;
		this->name = name;
		this->salary = salary;
		this->no_of_projects = no_of_projects;
		this->apraisal_score = apraisal_score;
	}

	virtual int hierarchy_number()
	{
		int hierarchy_number = 1;
		return hierarchy_number;
	}

	void input(int i, employee e)
	{
		cout << endl;
		cout << "Now getting the deatils of " << dataType(e) << " number " << i + 1 << endl;
		cout << "Enter the " << dataType(e) << " name :" << endl;
		cin >> name;
		cout << "Enter " << name << "'s  id :" << endl;
		cin >> id;
		cout << "Enter " << name << "'s salary :" << endl;
		cin >> salary;
		cout << "Enter the number of project " << name << " has finished: " << endl;
		cin >> no_of_projects;
		cout << "Enter the apraisal score of " << name << ":" << endl;
		cin >> apraisal_score;
	}

	string dataType(employee e)
	{
		string dataType;
		if (e.hierarchy_number() == 0)
		{
			dataType = "employee";
		}
		else if (e.hierarchy_number() == 1)
		{
			dataType = "manager";
		}
		else
		{
			dataType = "genral_manager";
		}
		return dataType;
	}

	void display(employee e)
	{
		cout << endl;
		cout << "The " << dataType(e) << " name is " << name << "." << endl;
		cout << "The id of " << name << " is " << id << "." << endl;
		cout << "The salary " << name << " is " << salary << " rupees." << endl;
		cout << "score of " << name << " is " << apraisal_score << " points." << endl;
	}
};

class manager : public employee
{
public:
	manager() : employee()
	{
		this->id = id;
		this->name = name;
		this->salary = salary;
		this->no_of_projects = no_of_projects;
		this->apraisal_score = apraisal_score;
	}

	virtual int hierarchy_number()
	{
		int hierarchy_number = 1;
		return hierarchy_number;
	}
};
class genralmanager : public employee
{
public:
	genralmanager() : employee()
	{
		this->id = id;
		this->name = name;
		this->salary = salary;
		this->no_of_projects = no_of_projects;
		this->apraisal_score = apraisal_score;
	}

	virtual int hierarchy_number()
	{
		int hierarchy_number = 2;
		return hierarchy_number;
	}
};

class department
{
public:
	int id;
	string name;

	department(int id, string name)
	{
		this->id = id;
		this->name = name;
	}

	virtual void display()
	{
		cout << "the department id is: " << id << endl;
		cout << "the department name is: " << name << endl;
		cout << endl;
	}

	virtual void appraiseemployee(employee *) = 0;

	~department() {}
};

class hrddepartment : virtual public department
{
public:
	hrddepartment(int id, string name) : department(id, name)
	{
		this->id = id;
		this->name = name;
	}

	void display()
	{
		cout << "the hrd id is :" << id << endl;
		cout << "the hrd name is :" << name << endl;
		cout << endl;
	}
	void appraiseemployee(employee e[2])
	{
		for (int i = 0; i < 2; i++)
		{
			try
			{
				if (e[i].no_of_projects == 0)
				{
					throw runtime_error("projects completed");
				}
				else
				{
					e[i].salary = e[i].salary + (e[i].no_of_projects * 10);
				}
			}
			catch (runtime_error &e)
			{
				cout << "the employee must complete atleast 1 project to get the salary raised but has completed 0 projects" << endl;
			}
		}
	}

	void find_best_performer(employee e[2])
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = i + 1; j < 2; j++)
			{
				if (e[j].apraisal_score < e[i].apraisal_score)
				{
					employee temp = e[j];
					e[j] = e[i];
					e[i] = temp;
				}
			}
		}
		cout << "the best employee is " << e[1].name << endl;
		cout << "The details of " << e[1].name << " are " << endl;
		e[1].display(e[1]);
	}
	virtual void print(employee e[2])
	{
		string input_name;
		cout << "enter the name of the employee you wants the details of" << endl;
		cin >> input_name;
		string designation;
		cout << "enter the designation of the employee you wants the details of [manager/genralmanager]" << endl;
		cin >> designation;
		if (designation == "manager")
		{
			for (int i = 0; i < 2; i++)
			{
				if (e[i].name == input_name)
				{
					cout << "the details of manager is: " << endl;
					e[i].display(e[i]);
				}
			}
		}
		else
		{
			if (designation == "genral_manager")
			{
				for (int i = 0; i < 2; i++)
				{
					if (e[i].name == input_name)
					{
						cout << "the details of manager is: " << endl;
						e[i].display(e[i]);
					}
				}
			}
		}
	}
	~hrddepartment()
	{
	}
};
int main()
{
	employee *e = new manager[2];
	for (int i = 0; i < 2; i++)
	{
		e[i].input(i, e[i]);
	}

	employee *e1 = new genralmanager[2];
	for (int i = 0; i < 2; i++)
	{
		e1[i].input(i, e1[i]);
	}
	// for(int i =0;i<2;i++){
	// e[i].display(e[i]);
	// }
	hrddepartment *hrd = new hrddepartment(1080, "AIML");
	hrd->display();
	hrd->find_best_performer(e);
	// hrd->find_best_performer(e1);
	hrd->appraiseemployee(e);

	// for(int i =0;i<2;i++){
	// e[i].display(e[i]);
	// }

	hrd->print(e);
	return 0;
}
