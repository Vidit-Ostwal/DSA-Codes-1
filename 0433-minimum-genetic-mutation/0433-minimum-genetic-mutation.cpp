class Solution
{
    vector<char> char_vect
    {
        'A',
        'C',
        'G',
        'T' };
    public:
        int minMutation(string start, string end, vector<string> &bank)
        {

            if (!start.compare(end))
                return 0;

            unordered_map<string, int> umap;
            for (int i = 0; i < bank.size(); i++)
                umap[bank[i]]++;

            unordered_map<string, int> visited;
            visited[start]++;

            int step = 0;
            queue<string> pq;
            pq.push(start);

            while (!pq.empty())
            {
                int size = pq.size();

                while (size)
                {
                    string temp = pq.front();
                    pq.pop();

                    if (!temp.compare(end))
                        return step;

                    for (int i = 0; i < temp.length(); i++)
                        for (int j = 0; j < char_vect.size(); j++)
                        {
                            char k = temp[i];
                            temp[i] = char_vect[j];

                            if (umap[temp] && !visited[temp])
                            {
                                visited[temp]++;
                                pq.push(temp);
                            }
                            temp[i] = k;
                        }
                  size--;
                }
                step++;
            }
            return -1;
        }
};