NAME = libmx.a

SRCS = src/mx_binary_search.c \
	src/mx_bubble_sort.c \
	src/mx_factorial_iter.c \
	src/mx_foreach.c \
	src/mx_hex_to_nbr.c \
	src/mx_nbr_to_hex.c \
	src/mx_pow.c \
	src/mx_print_alphabet.c \
	src/mx_printchar.c \
	src/mx_printint.c \
	src/mx_printstr.c \
	src/mx_sort_arr_int.c \
	src/mx_sqrt.c \
	src/mx_strcmp.c \
	src/mx_strcpy.c \
	src/mx_strdup.c \
	src/mx_strlen.c \
	src/mx_strnew.c \
	src/mx_create_node.c \
	src/mx_push_front.c \
	src/mx_push_back.c \
	src/mx_pop_front.c \
	src/mx_pop_back.c \
	src/mx_list_size.c \
	src/mx_sort_list.c \
	src/mx_quicksort.c \
	src/mx_count_substr.c \
	src/mx_count_words.c \
	src/mx_strtrim.c \
	src/mx_del_extra_spaces.c \
	src/mx_del_strarr.c \
	src/mx_print_strarr.c \
	src/mx_file_to_str.c \
	src/mx_get_char_index.c \
	src/mx_get_substr_index.c \
	src/mx_itoa.c \
	src/mx_print_unicode.c\
	src/mx_memccpy.c \
	src/mx_memchr.c \
	src/mx_memcmp.c \
	src/mx_memcpy.c \
	src/mx_memdel.c \
	src/mx_memmem.c \
	src/mx_memmove.c \
	src/mx_memrchr.c \
	src/mx_memset.c \
	src/mx_realloc.c \
	src/mx_replace_substr.c \
	src/mx_str_reverse.c \
	src/mx_strcat.c \
	src/mx_strdel.c \
	src/mx_strjoin.c \
	src/mx_strsplit.c \
	src/mx_strstr.c \
	src/mx_swap_char.c \
	src/mx_strncpy.c \
	src/mx_strndup.c \
	src/mx_strncmp.c \
	src/mx_read_line.c \
	src/mx_atoi.c \
	src/mx_get_island_arr.c \
	src/mx_data_processing.c \
	src/mx_show_all_paths.c \
	src/mx_print_paths.c

OUT = mx_binary_search.o \
	mx_bubble_sort.o \
	mx_factorial_iter.o \
	mx_foreach.o \
	mx_hex_to_nbr.o \
	mx_nbr_to_hex.o \
	mx_pow.o \
	mx_print_unicode.o\
	mx_print_alphabet.o \
	mx_printchar.o \
	mx_printint.o \
	mx_printstr.o \
	mx_sort_arr_int.o \
	mx_sqrt.o \
	mx_strcmp.o \
	mx_strcpy.o \
	mx_strdup.o \
	mx_strlen.o \
	mx_strnew.o \
	mx_create_node.o \
	mx_push_front.o \
	mx_push_back.o \
	mx_pop_front.o \
	mx_pop_back.o \
	mx_list_size.o \
	mx_sort_list.o \
	mx_quicksort.o \
	mx_count_substr.o \
	mx_count_words.o \
	mx_strtrim.o \
	mx_del_extra_spaces.o \
	mx_del_strarr.o \
	mx_print_strarr.o \
	mx_file_to_str.o \
	mx_get_char_index.o \
	mx_get_substr_index.o \
	mx_itoa.o \
	mx_memccpy.o \
	mx_memchr.o \
	mx_memcmp.o \
	mx_memcpy.o \
	mx_memdel.o \
	mx_memmem.o \
	mx_memmove.o \
	mx_memrchr.o \
	mx_memset.o \
	mx_realloc.o \
	mx_replace_substr.o \
	mx_str_reverse.o \
	mx_strcat.o \
	mx_strdel.o \
	mx_strjoin.o \
	mx_strsplit.o \
	mx_strstr.o \
	mx_swap_char.o \
	mx_strncpy.o \
	mx_strndup.o \
	mx_strncmp.o \
	mx_read_line.o \
	mx_atoi.o \
	mx_get_island_arr.o \
	mx_data_processing.o \
	mx_show_all_paths.o \
	mx_print_paths.o

OBJ_DIR = obj
INC = inc/libmx.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean
install:
	@mkdir obj
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -c *.c
	@ar rc $(NAME) $(OUT)
	@cp $(OUT) ./obj
	@/bin/rm -rf *.o
uninstall: clean
	@/bin/rm -rf $(NAME)
clean:
	@/bin/rm -rf *.h
	@/bin/rm -rf ./obj
	@/bin/rm -rf *.c
	@/bin/rm -rf $(OUT)
reinstall: uninstall clean all
