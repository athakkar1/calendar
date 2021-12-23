/*
Ajay Thakkar
E-115 LJ
I pledge my honor that I have abided by the Stevens Honor Code

Hello! This is my final project for E-115. For my final project, I decided to make a weekly scheduler that allows
the user to input when they want to wake up and go to sleep, and allows the user to enter different things that are
happening in their week. For example, if the user has any tasks like homework, errands, etc., they are able to input
when they need to do this task by and it will show up on the schedule. If the user has any events like a birthday party,
a baby shower, or a doctor's appointment, they are also able to input when this event starts and ends which will show up 
on the schedule. Finally, the user is able to display the schedule in the terminal or save it to a text file. The schedule is
made using military time and is in incriments of one hour. For this reason, when entering an hour please enter it in military time
and as an integer. 
*/

#include <iostream>
#include<string>
#include<fstream> //Included the fstream library so that the schedule can save to a text file.
#include<sstream> //Included the sstream library to convert integers to string values
#include<iomanip> //Included the iomanip library to allow for a table-like text output
#include<vector> //Included the vector library for tasks and events
using namespace std;

class createSchedule {
public:
	ofstream writer;
	ifstream reader;
	string week[8][25];
	string time;
	vector <string> tasks;//The following vectors are used in place of arrays, because arrays must have a pre-determined size, while vectors have dynamic memory storage. This is good because it is up to the user how many tasks or events they have, and so a dynamic storage must be used.
	vector <int> hours;
	vector <string> days;
	vector <string> events;
	vector <int> eventStartHours;
	vector <int> eventEndHours;
	vector <string> eventDays;
	createSchedule() { //Here, the headings in the first row are assigned their designated values.
		week[0][0] = "Time";
		week[1][0] = "Sunday";
		week[2][0] = "Monday";
		week[3][0] = "Tuesday";
		week[4][0] = "Wednesday";
		week[5][0] = "Thursday";
		week[6][0] = "Friday";
		week[7][0] = "Saturday";
	}
	void initialize() { //This function makes the first column of the schedule array into a a time column, which assigns each hour in military time to a place in the array.
		for (int i = 1; i < 25; i++) {
			time = to_string(i - 1); //I learned about the to_String function from https://en.cppreference.com/w/cpp/string/basic_string/to_string, and it allowed for a simple for loop to assign the military time hours.
			week[0][i] = time + ":00- ";
		}
		for (int i = 1; i < 8; i++) { //This assigns every other empty slot as "free time" for now
			for (int j = 1; j < 25; j++) {
				week[i][j] = "Free time";
			}
		}
		/*for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 25; j++) {
				cout << week[i][j] << endl;
			}
		}*/
	}
	void sameTimeWakeup() { //This function allows for a wake up hour, and a go to sleep hour to be inputted. 
		int samewakeuptime;
		int samesleeptime;
		cout << "At what hour would you like to wake up every day? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> samewakeuptime;
		cout << "At what hour would you like to sleep every day? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> samesleeptime;
		for (int i = 1; i < 8; i++) { //This for loop assigns "Wake up" and "Go to sleep" at the same time for every day.
			week[i][samewakeuptime + 1] = "Wake Up";
			week[i][samesleeptime + 1] = "Go to sleep";
		}
		for (int i = 1; i < 8; i++) { //This for loop makes every hour before the wake up time as "sleeping"
			for (int j = 1; j < (samewakeuptime + 1); j++) {
				week[i][j] = "Sleeping";
			}
		}
		for (int i = 1; i < 8; i++) { //This for loop makes every hour after the go to sleep time as "sleeping"
			for (int j = 24; j > (samesleeptime + 1); j--) {
				week[i][j] = "Sleeping";
			}
		}
		/*for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 25; j++) {
				cout << week[i][j] << endl;
			}
		}*/
	}
	void differentTimeWakeup() { //This function essentially uses the sameTimeWakeup code but allows for different wake up and sleeping times for each day.
		int wakeUp;
		int sleep;
		//SUNDAY
		cout << "On Sunday, at what hour would you like to wake up? Please enter the hour in military time  (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> wakeUp;
		cout << "On Sunday, at what hour would you like to sleep? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> sleep;
		week[1][wakeUp + 1] = "Wake up";
		week[1][sleep + 1] = "Go to sleep";
		for (int j = 1; j < (wakeUp + 1); j++) {
			week[1][j] = "Sleeping";
		}
		for (int j = 24; j > (sleep + 1); j--) {
			week[1][j] = "Sleeping";
		}
		//MONDAY
		cout << "On Monday, at what hour would you like to wake up? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> wakeUp;
		cout << "On Monday, at what hour would you like to sleep? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> sleep;
		week[2][wakeUp + 1] = "Wake up";
		week[2][sleep + 1] = "Go to sleep";
		for (int j = 1; j < (wakeUp + 1); j++) {
			week[2][j] = "Sleeping";
		}
		for (int j = 24; j > (sleep + 1); j--) {
			week[2][j] = "Sleeping";
		}
		//TUESDAY
		cout << "On Tuesday, at what hour would you like to wake up? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> wakeUp;
		cout << "On Tuesday, at what hour would you like to sleep? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> sleep;
		week[3][wakeUp + 1] = "Wake up";
		week[3][sleep + 1] = "Go to sleep";
		for (int j = 1; j < (wakeUp + 1); j++) {
			week[3][j] = "Sleeping";
		}
		for (int j = 24; j > (sleep + 1); j--) {
			week[3][j] = "Sleeping";
		}
		//WEDNESDAY
		cout << "On Wednesday, at what hour would you like to wake up? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> wakeUp;
		cout << "On Wednesday, at what hour would you like to sleep? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> sleep;
		week[4][wakeUp + 1] = "Wake up";
		week[4][sleep + 1] = "Go to sleep";
		for (int j = 1; j < (wakeUp + 1); j++) {
			week[4][j] = "Sleeping";
		}
		for (int j = 24; j > (sleep + 1); j--) {
			week[4][j] = "Sleeping";
		}
		//THURSDAY
		cout << "On Thursday, at what hour would you like to wake up? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> wakeUp;
		cout << "On Thursday, at what hour would you like to sleep? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> sleep;
		week[5][wakeUp + 1] = "Wake up";
		week[5][sleep + 1] = "Go to sleep";
		for (int j = 1; j < (wakeUp + 1); j++) {
			week[5][j] = "Sleeping";
		}
		for (int j = 24; j > (sleep + 1); j--) {
			week[5][j] = "Sleeping";
		}
		//FRIDAY
		cout << "On Friday, at what hour would you like to wake up? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> wakeUp;
		cout << "On Friday, at what hour would you like to sleep? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> sleep;
		week[6][wakeUp + 1] = "Wake up";
		week[6][sleep + 1] = "Go to sleep";
		for (int j = 1; j < (wakeUp + 1); j++) {
			week[6][j] = "Sleeping";
		}
		for (int j = 24; j > (sleep + 1); j--) {
			week[6][j] = "Sleeping";
		}
		//SATRUDAY
		cout << "On Saturday, at what hour would you like to wake up? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> wakeUp;
		cout << "On Saturday, at what hour would you like to sleep? Please enter the hour in military time below (i.e. 7 for 7 AM, and 19 for 7 PM): " << endl;
		cin >> sleep;
		week[7][wakeUp + 1] = "Wake up";
		week[7][sleep + 1] = "Go to sleep";
		for (int j = 1; j < (wakeUp + 1); j++) {
			week[7][j] = "Sleeping";
		}
		for (int j = 24; j > (sleep + 1); j--) {
			week[7][j] = "Sleeping";
		}
		/*for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 25; j++) {
				cout << week[i][j] << endl;
			}
		}*/
	}
	void displaySchedule() { //iomanip, setw function (which sets a width for each column), and overall table code from https://www.youtube.com/watch?v=G6MJ38PbL1o&ab_channel=ProfessorSpecioso
		for (int i = 0; i < 25; i++) { //Displays the actual table
			cout << setw(10) << week[0][i] << setw(20) << week[1][i] << setw(20) << week[2][i] << setw(20) << week[3][i] << setw(20) << week[4][i] << setw(20) << week[5][i] << setw(20) << week[6][i] << setw(20) << week[7][i] << endl;
		}
		if (tasks.size() > 0) { //Displays a key for the tasks
			cout << endl << "Tasks: " << endl;
			for (int i = 0; i < tasks.size(); i++) {
				cout << "Task " << i + 1 << ": " << tasks[i] << ", due on " << days[i] << " at " << hours[i] << ":00" << endl << endl;
			}
		}
		if (events.size() > 0) { //Displays a key for the events
			cout << endl << "Events: " << endl;
			for (int i = 0; i < events.size(); i++) {
				cout << "Event " << i + 1 << ": " << events[i] << ", which is on " << eventDays[i] << ", starting at " << eventStartHours[i] << ":00" << ", and ending at " << eventEndHours[i] << ":00" << endl << endl;
			}
		}
	}
	void saveSchedule() { //This function uses the same code as the displaySchedule function, and incorporates the writer and reader ifstream code from the contact book assignment
		writer.open("schedule.txt");
		for (int i = 0; i < 25; i++) {
			writer << setw(10) << week[0][i] << setw(20) << week[1][i] << setw(20) << week[2][i] << setw(20) << week[3][i] << setw(20) << week[4][i] << setw(20) << week[5][i] << setw(20) << week[6][i] << setw(20) << week[7][i] << endl;
		}
		if (tasks.size() > 0) {
			writer << endl << "Tasks: " << endl;
			for (int i = 0; i < tasks.size(); i++) {
				writer << "Task " << i + 1 << ": " << tasks[i] << ", due on " << days[i] << " at " << hours[i] << ":00" << endl << endl;
			}
		}
		if (events.size() > 0) {
			writer << endl << "Events: " << endl;
			for (int i = 0; i < events.size(); i++) {
				writer << "Event " << i + 1 << ": " << events[i] << ", which is on " << eventDays[i] << ", starting at " << eventStartHours[i] << ":00" << ", and ending at " << eventEndHours[i] << ":00" << endl << endl;
			}
		}
		writer.close();
	}
	void addTask() { //This function asks for a task name, the day of the task, and the time at which it is due. Then, the function displays this information in the schedule.
		string task;
		int hour;
		string day;
		int i;
		bool found = false;
		string vectorSize;
		cout << "Please tell us what your task is: " << endl;
		cin.ignore(); //There was a bug where sometimes the getline code would be skipped, and I learned that the cin.ignore function could fix it from https://stackoverflow.com/questions/12691316/getline-does-not-work-if-used-after-some-inputs
		getline(cin, task);//I learned the getline function from https://stackoverflow.com/questions/15446951/how-to-cin-whole-sentence-with-whitespaces, which allowed for full sentences to be inputted into a string variable.
		tasks.push_back(task); //The push_back function is a built in vector function which adds a value to a vector, which allows for dynamic storage. I learned about it from https://www.youtube.com/watch?v=bADtYBxrM8I&ab_channel=CppNuts
		cout << "What day do you need this task done by: " << endl;
		cin >> day;
		while (!found) { //this assigns an array variable that corresponds with the day that is inputted.
			if (day == "sunday" || day == "Sunday") {
				i = 1;
				days.push_back(day);
				found = true;
			}
			else if (day == "monday" || day == "Monday") {
				i = 2;
				days.push_back(day);
				found = true;
			}
			else if (day == "tuesday" || day == "Tuesday") {
				i = 3;
				days.push_back(day);
				found = true;
			}
			else if (day == "wednesday" || day == "Wednesday") {
				i = 4;
				days.push_back(day);
				found = true;
			}
			else if (day == "thursday" || day == "Thursday") {
				i = 5;
				days.push_back(day);
				found = true;
			}
			else if (day == "friday" || day == "Friday") {
				i = 6;
				days.push_back(day);
				found = true;
			}
			else if (day == "saturday" || day == "Saturday") {
				i = 7;
				days.push_back(day);
				found = true;
			}
		}
		cout << "At what time on " << day << " do you need this task done by: " << endl;
		cin >> hour;
		hours.push_back(hour);
		vectorSize = to_string(tasks.size());
		if (week[i][hour + 1] == "Free time" || week[i][hour + 1] == "Sleeping") { //This if else function inputs the task into the schedule array by using the previous inputs
			week[i][hour + 1] = "Task " + vectorSize;
		}
		else {
			week[i][hour + 1] = week[i][hour + 1] + "/Task " + vectorSize;
		}
	}
	void addEvent() { //This function uses essentially the same code as the addTask function, the only difference being a start and end time is inputted from the user
		string event;
		int eventStartHour;
		int eventEndHour;
		string eventDay;
		int i;
		bool found = false;
		string vectorSize;
		cout << "Please tell us what your event is: " << endl;
		/*if (events.size() == 0 && tasks.size()  == 0) {
			getline(cin, event);
		}
		else {
			cin.ignore();
			getline(cin, event);
		}*/
		cin.ignore();
		getline(cin, event);
		events.push_back(event);
		cout << "On what day is the event happening: " << endl;
		cin >> eventDay;
		while (!found) {
			if (eventDay == "sunday" || eventDay == "Sunday") {
				i = 1;
				eventDays.push_back(eventDay);
				found = true;
			}
			else if (eventDay == "monday" || eventDay == "Monday") {
				i = 2;
				eventDays.push_back(eventDay);
				found = true;
			}
			else if (eventDay == "tuesday" || eventDay == "Tuesday") {
				i = 3;
				eventDays.push_back(eventDay);
				found = true;
			}
			else if (eventDay == "wednesday" || eventDay == "Wednesday") {
				i = 4;
				eventDays.push_back(eventDay);
				found = true;
			}
			else if (eventDay == "thursday" || eventDay == "Thursday") {
				i = 5;
				eventDays.push_back(eventDay);
				found = true;
			}
			else if (eventDay == "friday" || eventDay == "Friday") {
				i = 6;
				eventDays.push_back(eventDay);
				found = true;
			}
			else if (eventDay == "saturday" || eventDay == "Saturday") {
				i = 7;
				eventDays.push_back(eventDay);
				found = true;
			}
		}
		cout << "At what time on " << eventDay << " does this event start: " << endl;
		cin >> eventStartHour;
		eventStartHours.push_back(eventStartHour);
		cout << "At what time on " << eventDay << " does this event end: " << endl;
		cin >> eventEndHour;
		eventEndHours.push_back(eventEndHour);
		vectorSize = to_string(events.size());
		for (int j = eventStartHour + 1; j < eventEndHour + 2; j++) {
			if (week[i][j] == "Free time" || week[i][j] == "Sleeping") {
				week[i][j] = "Event " + vectorSize;
			}
			else {
				week[i][j] = week[i][j] + "/Event " + vectorSize;
			}
		}
	}
};

int main() {
		createSchedule contact; //This initializes a class variable in the main function
		bool wakeupFalse = false;
		string wakeup;
		int selection;
		contact.initialize(); //Initialize function is called to create the schedule template
		cout << "Hello! Try out our weekly scheduler for a more effecient life!" << endl;
		cout << "First, we need to figure out your sleeping schedule. For this week, would you like to wake up and go to sleep at the same time?" << endl << "Type yes to wake up and sleep at the same time or no to wake up and sleep at different times: " << endl;
		while (!wakeupFalse) { //A while loop is made to determine if the user wants to wake up and sleep at the same time or different times.
			cin >> wakeup;
			if (wakeup == "yes") {
				contact.sameTimeWakeup();
				wakeupFalse = true;
			}
			else if (wakeup == "no") {
				contact.differentTimeWakeup();
				wakeupFalse = true;
			}
			else {
				cout << "Sorry, please enter yes if you want to wake up and sleep at the same time, or no if you want to wake up and sleep at different times each day: " << endl;
			}
		}
		cout << "Below is an empty schedule including the times you wake up and go to sleep: " << endl;
		contact.displaySchedule();
		cout << "Now you have multiple options in creating your schedule, which can be viewed below: " << endl;
		while (1) { //A while/switch loop is used like in previous assignments for the user to pick different actions
			cout << "Press 1 to add tasks, 2 to add events, 3 to view your schedule, 4 to save your schedule to a .txt file, or anything else to exit: " << endl;
			cin >> selection;
			switch (selection) {
			case 1:
				contact.addTask();
				break;
			case 2:
				contact.addEvent();
				break;
			case 3:
				contact.displaySchedule();
				break;
			case 4:
				contact.saveSchedule();
				break;
			default:
				cout << "Thank you! Displaying your final schedule..." << endl;
				contact.displaySchedule();
				exit(1);
			}
		}
		return 0;
}