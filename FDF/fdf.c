#include "fdf.h"

#define WIDTH 800
#define HEIGHT 600
#define SPACING 30
#define ANGLE 0.7

#define WHITE 0xFFFFFFFF
#define BLUE 0xFF00FF00

uint32_t interpolate_color(uint32_t start_color, uint32_t end_color, float t) {
    uint8_t r = ((start_color >> 24) & 0xFF) + t * (((end_color >> 24) & 0xFF) - ((start_color >> 24) & 0xFF));
    uint8_t g = ((start_color >> 16) & 0xFF) + t * (((end_color >> 16) & 0xFF) - ((start_color >> 16) & 0xFF));
    uint8_t b = ((start_color >> 8) & 0xFF) + t * (((end_color >> 8) & 0xFF) - ((start_color >> 8) & 0xFF));
    uint8_t a = (start_color & 0xFF) + t * ((end_color & 0xFF) - (start_color & 0xFF));
    return (r << 24 | g << 16 | b << 8 | a);
}

void free_map(t_map *map) {
    int i = 0;
    while (i < map->height) free(map->points[i++]);
    free(map->points);
    free(map);
}

int count_columns(char *line) {
    int count = 0;
    char **split = ft_split(line, ' ');
    while (split[count]) free(split[count++]);
    free(split);
    return count;
}

void draw_line(mlx_image_t *img, t_point p1, t_point p2, uint32_t start_color, uint32_t end_color)
{
    int dx = abs(p2.x - p1.x), dy = abs(p2.y - p1.y), sx = (p1.x < p2.x) ? 1 : -1, sy = (p1.y < p2.y) ? 1 : -1;
    int err = dx - dy;
	int steps = (dx > dy) ? dx : dy;
	int step_count = 0;
    while (1) {
        float t = (float)step_count / steps;
        uint32_t color = interpolate_color(start_color, end_color, t);
        if (p1.x >= 0 && p1.x < (int)img->width && p1.y >= 0 && p1.y < (int)img->height)
            mlx_put_pixel(img, p1.x, p1.y, color);
        if (p1.x == p2.x && p1.y == p2.y) break;
        int e2 = err * 2;
        if (e2 > -dy) { err -= dy; p1.x += sx; }
        if (e2 < dx) { err += dx; p1.y += sy; }
        step_count++;
    }
}

void draw_map(mlx_image_t *img, t_map *map, int offset_x, int offset_y) {
    int total_width = ((map->width - 1) - (map->height - 1)) * SPACING * cos(ANGLE);
    int total_height = ((map->width - 1) + (map->height - 1)) * SPACING * sin(ANGLE);
    int x_offset = (WIDTH - total_width) / 2 + offset_x;
    int y_offset = (HEIGHT - total_height) / 2 + offset_y;
    int y = 0;
    while (y < map->height) {
        int x = 0;
        while (x < map->width) {
            int iso_x = (x - y) * cos(ANGLE) * SPACING + x_offset;
            int iso_y = (x + y) * sin(ANGLE) * SPACING - map->points[y][x].y + y_offset;
            if (iso_x >= 0 && iso_x < (int)img->width && iso_y >= 0 && iso_y < (int)img->height)
                mlx_put_pixel(img, iso_x, iso_y, WHITE);
            if (x < map->width - 1) {
                int next_iso_x = ((x + 1) - y) * cos(ANGLE) * SPACING + x_offset;
                int next_iso_y = ((x + 1) + y) * sin(ANGLE) * SPACING - map->points[y][x + 1].y + y_offset;
                uint32_t color = (map->points[y][x].z > 0 || map->points[y][x + 1].z > 0) ? BLUE : WHITE;
                draw_line(img, (t_point){iso_x, iso_y, 0}, (t_point){next_iso_x, next_iso_y, 0}, color, WHITE);
            }
            if (y < map->height - 1) {
                int next_iso_x = (x - (y + 1)) * cos(ANGLE) * SPACING + x_offset;
                int next_iso_y = (x + (y + 1)) * sin(ANGLE) * SPACING - map->points[y + 1][x].y + y_offset;
                uint32_t color = (map->points[y][x].z > 0 || map->points[y + 1][x].z > 0) ? BLUE : WHITE;
                draw_line(img, (t_point){iso_x, iso_y, 0}, (t_point){next_iso_x, next_iso_y, 0}, color, WHITE);
            }
            x++;
        }
        y++;
    }
}

t_map *read_file(char *filename) {
    int fd = open(filename, O_RDONLY), line_count = 0;
    if (fd < 0) return NULL;
    t_map *map = (t_map *)malloc(sizeof(t_map));
    char **lines = NULL, *line;
    while ((line = get_next_line(fd))) {
        if (map->height == 0) map->width = count_columns(line);
        map->height++;
        lines = realloc(lines, sizeof(char *) * map->height);
        lines[line_count++] = line;
    }
    map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
    for (int i = 0; i < map->height; i++) map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
    for (int i = 0; i < line_count; i++) {
        char **split = ft_split(lines[i], ' ');
        for (int x = 0; split[x]; x++) {
            map->points[i][x].x = x * SPACING;
            map->points[i][x].y = (split[x][0] == '1' && split[x][1] == '0') ? 35 : 0;
            map->points[i][x].z = (split[x][0] == '1' && split[x][1] == '0') ? 1 : 0;
            free(split[x]);
        }
        free(split);
        free(lines[i]);
    }
    free(lines);
    close(fd);
    return map;
}

void ft_hook(void* param) {
    mlx_t *mlx = (mlx_t*)param;
    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);
}

int32_t main(int argc, char **argv) {
    if (argc != 2) return 1;

    t_map *map = read_file(argv[1]);
    if (!map) return 1;

    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    if (!mlx) {
        free_map(map);
        return 1;
    }

    mlx_image_t* image = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!image) {
        mlx_terminate(mlx);
        free_map(map);
        return 1;
    }

    ft_memset(image->pixels, 0, image->width * image->height * sizeof(int32_t));
    if (mlx_image_to_window(mlx, image, 0, 0) == -1) {
        mlx_delete_image(mlx, image);
        mlx_terminate(mlx);
        free_map(map);
        return 1;
    }

    draw_map(image, map, 0, 0);
    mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    free_map(map);
    return 0;
}