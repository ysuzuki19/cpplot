# cpplot
C++ gnuplot interface

# HOW TO USE
## with vector<T>

```
vector<int> v(100);
for (int i=0; i<v.size(); ++i) {
  v[i] = i;
}

Cpplot cplt;
cplt.plot(v); // i-v[i] graph
```

## with vector<pair<T,T>>

```
vector<pair<int,int>> v(100);
for (int i=0; i<v.size(); ++i) {
  v[i].first = i;
  v[i].second = i;
}

Cpplot cplt;
cplt.setLabels("first", "second"); // optional
cplt.plot(v); // v[i].first-v[i].second graph
```
