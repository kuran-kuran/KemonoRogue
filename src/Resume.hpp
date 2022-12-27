#ifndef RESUME_HPP
#define RESUME_HPP

class Resume
{
public:
	struct Data
	{
		// game
		int floor;
		int crystal;
		int player_type;
		// player
		int hp_max;
		int hp;
		// item
		int item_id;
		int item_grade;
		int item_dcy;
		int item_add_dcy;
		// checksum
		int check_sum;
	};
	static bool Load(Resume::Data* data);
	static void Save(Resume::Data* data);
	static void DeleteResumeDataFile(void);
};

#endif
