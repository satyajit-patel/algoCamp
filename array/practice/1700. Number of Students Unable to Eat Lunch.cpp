/*
        Constraints:
        1 <= students.length, sandwiches.length <= 100
        students.length == sandwiches.length
        sandwiches[i] is 0 or 1.
        students[i] is 0 or 1.

        Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
        Output: 3

        Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
        Output: 0 
    */

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        vector<int> student_type(2, 0);
        for(int i=0; i<n; i++) {
            student_type[students[i]]++;
        }

        for(int i=0; i<n; i++) {
            int food_type = sandwiches[i];
            if(student_type[food_type] == 0) {
                return n - i; // that much stud will not get anything
            }
            student_type[food_type]--;
        }

        return 0;
    }