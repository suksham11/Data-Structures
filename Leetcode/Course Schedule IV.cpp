class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] pre, int[][] queries) {
        boolean mat[][] = new boolean[numCourses][numCourses];
        for(int i=0 ; i<pre.length; i++){
            int s = pre[i][0];
            int d = pre[i][1];
            mat[s][d] = true;
        }

        for(int k=0 ; k<numCourses ; k++){
            for(int s=0 ; s<numCourses ; s++){
                for(int d=0 ; d<numCourses ; d++){
                    mat[s][d] = mat[s][d] || (mat[s][k] && mat[k][d]);
                }
            }
        }

        List<Boolean> ans = new ArrayList<>();
        for(int i=0 ; i<queries.length ; i++){
            int s = queries[i][0];
            int d = queries[i][1];
            ans.add(mat[s][d]);
        }
        return ans;
    }
}
