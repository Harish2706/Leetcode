//https://youtu.be/JnJGIE7porM?si=C7QjzB4vhYlUIrTF
/*observation to calculate the no of matrix that have i,j as bottom ,the formula is (j - prevsmallindex) * hegiht
  if any submatrix with less height is there we should add that also
*/
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int>hist(m);
        int currcount,total= 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 1 ) hist[j] +=1;
                else hist[j] = 0;
            }
            stack<vector<int>>st;
            //{height,index,prevcount}
            st.push({-1,-1,0});
            for(int j = 0;j<m;j++){
                  while(st.top()[0]>hist[j]) st.pop();
                  currcount = (j-st.top()[1])*hist[j];
                  currcount += st.top()[2];
                  total += currcount;
                  st.push({hist[j],j,currcount});
            }
        }
        return total;
    }
};