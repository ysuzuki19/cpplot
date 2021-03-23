# cpplot
C++ gnuplot interface

# INSTALL gnuplot

```bash
## LINUX
$ sudo apt install gnuplot

## MACOS
$ brew install gnuplot
```

# HOW TO USE
## CLONE REPOSITORY

```bash
$ git clone https://github.com/ysuzuki19/cpplot
```


## RUN SAMPLEs
1. 2D graph with `vector<>`

```bash
$ cd cpplot/sample/vec
$ make
$ ./project
```

1. 2D graph with `vector<pair<Tx,Ty>>`

```bash
$ cd cpplot/sample/vec_pair
$ make
$ ./project
```

1. 3d graph with `vector<vector<T>>`

```bash
$ cd cpplot/sample/vec_vec
$ make
$ ./project
```

1. 3d graph with `vector<tuple<Tx,Ty,Tz>>`

```bash
$ cd cpplot/sample/vec_tuple
$ make
$ ./project
```

## APIs
### constructor

```cpp
Cpplot cplt; // open gnuplot without options
```

```cpp
Cpplot cplt(option); // open gnuplot with option

// example
Cpplot cplt("--persist"); // open `gnuplot --persist`
```

### set style (optional)
default plot style is `with lines`.

```cpp
cplt.setStyle("lines"); // plot with lines
```

### set range (optional)

```cpp
cplt.setXRange(0, 100);
cplt.setYRange(0, 100);
cplt.setZRange(0, 100);
```

### set label (optional)

```cpp
cplt.setXLabel(label_name);
cplt.setYLabel(label_name);
cplt.setZLabel(label_name);

cplt.setLabels(x_label_name, y_label_name);
cplt.setLabels(x_label_name, y_label_name, z_label_name);
```

### plot !!
#### 2d graph

```cpp
cplt.plot(vec);
cplt.plot(vec_pair);
```

#### 3d graph

```cpp
cplt.splot(vec_vec);
cplt.splot(vec_tuple);
```

# THANK YOU FOR READING
