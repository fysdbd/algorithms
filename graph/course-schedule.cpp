
/*
    course schdule

    description(leetcoe
		https://leetcode.com/problems/course-schedule/
		)


    There are a total of n courses you have to take, labeled from 0 to n - 1.

    Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

    Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

    notes: solution in BFS by using a queue
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
       
        // state variables
        int taken = 0;
        queue<int> available_courses;
        map<int, int> course_preqs;
        for (int course = 0; course < numCourses; course++) { course_preqs[course] = 0; }
        map<int, vector<int>> courses_affected;
        
        for (auto entry : prerequisites) {
            course_preqs[entry.first]++;
            courses_affected[entry.second].push_back(entry.first);
        }
        for (auto item : course_preqs) { if (item.second == 0) { available_courses.push(item.first); taken++; } }
        
        while (!available_courses.empty()) {
            int course_taken = available_courses.front();
            available_courses.pop();
            for (auto & affected_course : courses_affected[course_taken]) {
                if(--course_preqs[affected_course] == 0) {
                    available_courses.push(affected_course);
                    taken++;
                }
            }
        }
        
        return numCourses == taken;
    }
};

