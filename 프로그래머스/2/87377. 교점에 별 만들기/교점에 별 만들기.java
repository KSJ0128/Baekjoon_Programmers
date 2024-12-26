import java.util.*;
import java.io.*;

// 두 직선이 평행 또는 일치하는지 확인
// 교점 공식을 통해 교점 저장 -> 어떤 자료구조로..? 저장 과정에서 정수 아니면 pass
// 최소 x, y와 최대 x, y로 전체 . 찍고 다시 교점 위치에 별 찍기

class Point {
    long px;
    long py;

    public Point(long x, long y) {
        this.px = x;
        this.py = y;
    }
}

class Grid {
    long minX, minY, maxX, maxY;
    int width, height;
    Set<Point> pointList;
  
    public Grid() {
        this.minX = Long.MAX_VALUE;
        this.minY = Long.MAX_VALUE;
        this.maxX = Long.MIN_VALUE;
        this.maxY = Long.MIN_VALUE;
        
        this.pointList = new HashSet<>();
    }
    
    void calculate() {
        for (Point p : pointList) {
            minX = Math.min(minX, p.px);
            minY = Math.min(minY, p.py);
            maxX = Math.max(maxX, p.px);
            maxY = Math.max(maxY, p.py);
        }
        
        width = (int) (maxX - minX + 1);
        height = (int) (maxY - minY + 1);
    }
    
    String[] draw() {
        char[][] grid = new char[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                grid[i][j] = '.'; // 초기값
            }
        }
        
        // 교점에 '*' 추가
        for (Point point : pointList) {
            int x = (int) (point.px - minX);
            int y = (int) (maxY - point.py); // Y 좌표 반전
            grid[y][x] = '*';
        }
        
        String[] answer = new String[height];
        for (int i = 0; i < height; i++) {
            answer[i] = new String(grid[i]);
        }

        return answer;
    }
}

class Solution {
    public boolean isInt(long val, long denominator) {
        return val % denominator == 0;
    }
        
    public String[] solution(int[][] line) {
        Grid myGrid = new Grid();
        
        for (int i = 0; i < line.length - 1; i++) {
            for (int j = i + 1; j < line.length; j++) {
                // 두 직선 평행 or 일치 케이스 제외
                long denominator = (long)line[i][0] * line[j][1] - (long)line[i][1] * line[j][0];
                if (denominator == 0)
                    continue;
                
                long x = ((long)line[i][1] * line[j][2] - (long)line[i][2] * line[j][1]);
                long y = ((long)line[i][2] * line[j][0] - (long)line[i][0] * line[j][2]);
                
                if (isInt(x, denominator) && isInt(y, denominator)) {
                    myGrid.pointList.add(new Point(x / denominator, y / denominator));
                }
            }
        }
        
        myGrid.calculate();
        return myGrid.draw();
    }
}