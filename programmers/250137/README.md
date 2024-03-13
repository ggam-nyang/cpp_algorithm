
### 풀이 생각
1. attacks를 반복하며, 각 공격에 대해 조건 처리
   2. 공격 시간과 현재 시간의 차이만큼 회복 진행
   3. 공격 시간과 현재 시간이 동일해지면 공격 진행
4. 공격 진행 후 조건 처리
   5. 최대체력이 0보다 작으면 -1
   6. 최대체력이 0보다 크면 1번으로 다음 공격 진행

### 풀이
풀이 생각대로 풀었고, 단순한 시뮬레이션 문제였다.  
주의할 점은, currTime의 순서와 연속 회복 횟수, 공격 시간을 순서에 맞게 증감해야한다.

### 아쉬운 점
`recoveryCount == bi.totalTime`  
연속 회복 횟수 == 조건의 연속 횟수  에서 실수로 조건의 연속 회복량으로 실수했다ㅠ  
알고리즘은 논리있는 풀이도 중요하지만 내 생각을 실수 없이 빠르게 구현해야한다!!

