#ifndef Due_date_h_
#define Due_date_h_

struct DueDate
{
public:
	int mMonth;
	int mDay;
	int mYear;

	bool operator<(DueDate n);

	bool operator==(DueDate n);

	void operator=(DueDate n) { mMonth = n.mMonth; mDay = n.mDay; mYear = n.mYear; }

	DueDate();
	DueDate(int, int, int);
	~DueDate();
};


#endif // !Due_date_h
