
/*

	Course Schedule II

	description(leetcode
		    https://leetcode.com/problems/course-schedule-ii/

	There are a total of n courses you have to take, labeled from 0 to n - 1.
	Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
	Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
	There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

	For example:

	2, [[1,0]]
	There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

	4, [[1,0],[2,0],[3,1],[3,2]]
	There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

	Note:
	The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 


	note:
	pretty much the same thing with course schedule i
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
       
        // state variables
        queue<int> available_courses;
        vector<int> result;
        map<int, int> course_preqs;
        for (int course = 0; course < numCourses; course++) { course_preqs[course] = 0; }
        map<int, vector<int>> courses_affected;
        
        for (auto entry : prerequisites) {
            course_preqs[entry.first]++;
            courses_affected[entry.second].push_back(entry.first);
        }
        for (auto item : course_preqs) {
            if (item.second == 0) {
                available_courses.push(item.first);
                result.push_back(item.first);
            }
        }
        
        while (!available_courses.empty()) {
            int course_taken = available_courses.front();
            available_courses.pop();
            for (auto & affected_course : courses_affected[course_taken]) {
                if(--course_preqs[affected_course] == 0) {
                    available_courses.push(affected_course);
                    result.push_back(affected_course);
                }
            }
        }
        
        if (result.size() == numCourses) { return result; }
        return {};
    }
};


