class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        
        // 1. Build a long long prefix sum to safely run upper_bound
        vector<long long> pref(n);
        pref[0] = tasks[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + tasks[i];
        }
        
        vector<int> ans;
        int task_idx = 0;              // Tracks which task we are currently on
        long long time_spent_on_task = 0; // Tracks partially completed time for task_idx
        
        for(int shift_time : shifts) {
            // Calculate base offset from the prefix array
            long long base_time = (task_idx > 0) ? pref[task_idx - 1] : 0;
            
            // Total virtual target time we are trying to clear in this shift
            long long target_time = base_time + time_spent_on_task + shift_time;
            
            // Binary search to find how far we get
            auto it = upper_bound(pref.begin(), pref.end(), target_time);
            int completed_up_to = distance(pref.begin(), it);
            
            if(completed_up_to == n) {
                // RESTART RULE: All tasks completed! 
                ans.push_back(0);
                task_idx = 0;             // Reset back to the first task for next shift
                time_spent_on_task = 0;   // Clear partial work
            } else {
                // Tasks still remain unfinished
                ans.push_back(n - completed_up_to);
                task_idx = completed_up_to; // Next shift resumes exactly from this task
                
                // Calculate exactly how much time was partially spent on this unfinished task
                long long completed_tasks_time = (task_idx > 0) ? pref[task_idx - 1] : 0;
                time_spent_on_task = target_time - completed_tasks_time;
            }
        }
        
        return ans;
    }
};
