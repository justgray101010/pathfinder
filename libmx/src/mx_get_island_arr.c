#include "libmx.h"

static int init(char *temp_line, char *island1, char *island2) {
    int len1 = mx_get_char_index(temp_line, '-');
    int len2 = mx_get_char_index(temp_line, ',') - len1 - 1;
    char *temp = mx_strdup(temp_line);
    int dist = 0;
    mx_strncpy(island1, temp, len1);
    temp = temp + len1 + 1;
    mx_strncpy(island2, temp, len2);
    temp = temp + len2 + 1;
    dist = mx_atoi(temp);
    return dist;
}

static void case0(island **arr, int number, char *island1, char *island2, int dist) {
    island *first = (island*) malloc(sizeof(island));
    first->name = island1;
    first->bridge_to_islands = (char**) malloc(sizeof(char*) * number);
    first->distance_between_islands = (int*) malloc(sizeof(int) * number);
    first->bridge_to_islands[0] = island2;
    first->distance_between_islands[0] = dist;
    island *second = (island*) malloc(sizeof(island));
    second->name = island2;
    second->bridge_to_islands = (char**) malloc(sizeof(char*) * number);
    second->distance_between_islands = (int*) malloc(sizeof(int) * number);
    second->bridge_to_islands[0] = island1;
    second->distance_between_islands[0] = dist;
    int i = 0;
    for (; i < number; i++) {
        if (mx_strlen(arr[i]->name) == 0)
            break;
    }
    if (i == number) {
        write(2, "error: invalid number of islands\n", mx_strlen("error: invalid number of islands\n"));
        exit(1);
    }
    arr[i] = first;
    arr[i+1] = second;
}

static void case1(island **arr, int number, char *island1, char *island2, int dist) {
    int i = 0;
    int j = 0;
    for (; i < number; i++) {
        if (mx_strcmp(arr[i]->name, island1) == 0) {
            for (; j < number; j++) {
                if (arr[i]->distance_between_islands[j] == 0)
                    break;
            }
            arr[i]->bridge_to_islands[j] = island2;
            arr[i]->distance_between_islands[j] = dist;
        }
    }
    island *second = (island*) malloc(sizeof(island));
    second->name = island2;
    second->bridge_to_islands = (char**) malloc(sizeof(char*) * number);
    second->distance_between_islands = (int*) malloc(sizeof(int) * number);
    second->bridge_to_islands[0] = island1;
    second->distance_between_islands[0] = dist;
    i = 0;
    for (; i < number; i++) {
        if (mx_strlen(arr[i]->name) == 0)
            break;
    }
    if (i == number) {
        write(2, "error: invalid number of islands\n", mx_strlen("error: invalid number of islands\n"));
        exit(1);
    }
    arr[i] = second;
}

static void case2(island **arr, int number, char *island1, char *island2, int dist) {
    int i = 0, k = 0;
    int j = 0, n = 0;
    for (; i < number; i++) {
        if (mx_strcmp(arr[i]->name, island1) == 0) {
            for (; k < number; k++) {
                if (arr[i]->distance_between_islands[k] == 0)
                    break;
            }
            arr[i]->bridge_to_islands[k] = island2;
            arr[i]->distance_between_islands[k] = dist;
        }
    }
    for (; j < number; j++) {
        if (mx_strcmp(arr[j]->name, island2) == 0) {
            for (; n < number; n++) {
                if (arr[j]->distance_between_islands[n] == 0)
                    break;
            }
            arr[j]->bridge_to_islands[n] = island1;
            arr[j]->distance_between_islands[n] = dist;
        }
    }
}
static void mx_printerr(int count, char *temp_line) {
    int t = 0;
        for (; temp_line[t] != '-'; t++) {
            if ((temp_line[t] < 97 || temp_line[t] > 122) 
            && (temp_line[t] < 65 || temp_line[t] > 90)) {
                write(2, "error: line ", mx_strlen("error: line "));
                char *s = mx_itoa(count);
                write(2, s, mx_strlen(s));
                write(2, " isn't valid\n", mx_strlen(" isn't valid\n"));
                exit(1);
            }
        }
        for (++t; temp_line[t] != ','; t++) {
            if ((temp_line[t] < 97 || temp_line[t] > 122) 
            && (temp_line[t] < 65 || temp_line[t] > 90)) {
                write(2, "error: line ", mx_strlen("error: line "));
                char *s = mx_itoa(count);
                write(2, s, mx_strlen(s));
                write(2, " isn't valid\n", mx_strlen(" isn't valid\n"));
                exit(1);
            }
        }
        for (++t; temp_line[t] != '\0'; t++) {
            if (temp_line[t] < 48 || temp_line[t] > 57) {
                write(2, "error: line ", mx_strlen("error: line "));
                char *s = mx_itoa(count);
                write(2, s, mx_strlen(s));
                write(2, " isn't valid\n", mx_strlen(" isn't valid\n"));
                exit(1);
            }
        }
}
int mx_get_island_arr(island **arr, int number, char *argv[]) {
    int max_distance = 0;
    int fd = open(argv[1], O_RDONLY);
    char *file = mx_file_to_str(argv[1]);
    int n = 0;
    for (int i = 0; file[i]; i++)
        if (file[i] == '\n')
            n++;
    char *temp_line = (char*) malloc(sizeof(char) * 100);
    int count = 1;
    mx_read_line(&temp_line, 4, '\n', fd);
    while (n-- != 1) {
        mx_read_line(&temp_line, 4, '\n', fd);
        count++;
        mx_printerr(count, temp_line);
        int len1 = mx_get_char_index(temp_line, '-');
        int len2 = mx_get_char_index(temp_line, ',') - len1 - 1;
        char *island1 = mx_strnew(len1);
        char *island2 = mx_strnew(len2);
        int dist = init(temp_line, island1, island2);
        max_distance += dist;
        int island_case = mx_data_processing(arr, number, island1, island2);
        if (island_case == 0) {
            case0(arr, number, island1, island2, dist);
        }
        if (island_case == 1) {
            case1(arr, number, island1, island2, dist);
        }
        if (island_case == 2) {
            case1(arr, number, island2, island1, dist);
        }
        if (island_case == 3) {
            case2(arr, number, island1, island2, dist);
        }
    }
    return max_distance + 1;
}
