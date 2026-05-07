# project-drone

STM32H723 Nucleo 기반으로 쿼드콥터 비행제어 펌웨어를 직접 이해하고 구현하기 위한 학습형 프로젝트입니다.

이 프로젝트의 1차 목표는 빠르게 드론을 띄우는 것이 아니라, ESC 제어, IMU 센서 처리, 자세 추정, PID 제어, 모터 믹싱, failsafe, 고도 센서 처리 같은 비행제어 핵심 요소를 단계별로 직접 구현하며 펌웨어 역량을 키우는 것입니다.

이후에는 Kakute H7 Mini 같은 상용 STM32H7 기반 FC와 Raspberry Pi를 결합하여 영상 처리, 장애물 감지, AI 판단, 자율비행 실험으로 확장합니다.

## 개발 전략

### Stage 1. STM32H723 Nucleo 기반 학습용 FC

- Betaflight의 구조와 개념을 참고하되, H723 Nucleo에 맞게 작은 비행제어 펌웨어를 직접 구현합니다.
- 목표는 실제 자유비행이 아니라 책상 위 테스트, 프롭 없는 모터 반응 검증, 고정 지그 안정화, 제한적 고도 제어 실험입니다.
- 개별 ESC 4개를 사용하여 모터 4개를 각각 제어합니다.

### Stage 2. Kakute H7 Mini 기반 실기체 구성

- H723에서 학습한 내용을 바탕으로 상용 H7 FC 구조를 이해합니다.
- 실제 비행 플랫폼은 Kakute H7 Mini 같은 검증된 FC에서 Betaflight, PX4, ArduPilot 중 적합한 펌웨어를 사용합니다.
- FPV/수동 안정화 확인은 Betaflight, Raspberry Pi companion 및 자율비행 확장은 PX4 또는 ArduPilot을 우선 검토합니다.

### Stage 3. Raspberry Pi Companion Computer 확장

- Raspberry Pi는 영상 처리, 라이다/ToF 센서 처리, 장애물 감지, AI 판단, 경로 계획을 담당합니다.
- FC는 모터 제어, 자세 안정화, 센서 융합, failsafe를 담당합니다.
- Raspberry Pi는 모터 출력을 직접 보내지 않고, 목표 자세/속도/위치/고도 같은 고수준 명령만 FC에 전달합니다.

```text
Raspberry Pi = 판단 / 계산 / 영상 / AI / 장애물 회피
FC           = 실시간 자세제어 / 모터제어 / 센서융합 / failsafe
```

## 목표

### 1차 목표: H723 학습용 FC

- ESC 4개를 개별 제어하는 PWM 출력 구현
- MPU-6500 기반 자이로/가속도 데이터 수집
- BMP388 기반 기압/고도 데이터 수집
- 자이로 bias 보정 및 자세 추정 구현
- Rate PID 및 Angle PID 구현
- 쿼드콥터 X-frame 모터 믹싱 구현
- arm/disarm 및 failsafe 상태 머신 구현
- 프롭 없는 상태에서 모터 보정 방향 검증
- 1축/2축 고정 지그에서 자세 안정화 실험
- 하방 ToF/LiDAR 추가 시 제한적 고도 유지 실험

### 2차 목표: Kakute H7 Mini + Raspberry Pi

- 상용 H7 FC에서 실제 드론 플랫폼 구성
- Raspberry Pi와 FC 통신 구성
- 영상 스트리밍 실험
- 라이다/ToF 또는 카메라 기반 장애물 감지
- Raspberry Pi에서 목표 속도/위치 명령 생성
- PX4/ArduPilot 기반 자율비행 구조 학습

### 장기 목표

- GPS 기반 위치 유지 및 자율비행 실험
- 장애물 회피 알고리즘 실험
- AI 기반 센서 보정/위험도 판단/회피 판단 실험
- 직접 구현한 H723 펌웨어와 Betaflight/PX4/ArduPilot 구조 비교

## 하드웨어 구성

### Stage 1. STM32H723 Nucleo 학습용 구성

| 구분 | 부품 | 역할 | 비고 |
| --- | --- | --- | --- |
| MCU 개발보드 | STM32H723 Nucleo | 학습용 FC 구현 | 실제 비행용보다는 펌웨어 검증용 |
| 모터 | RS2205 2300KV x4 | 추진 | 프롭 제거 상태에서 테스트 |
| ESC | BLHeli_S 30A x4 | 모터 개별 구동 | 4-in-1 ESC가 아니라 개별 ESC 4개 사용 |
| IMU | MPU-6500 | 자이로/가속도 기반 자세 추정 | SPI 연결 우선 검토 |
| 기압계 | BMP388 | 기압/고도 추정 | 초기에는 로깅과 필터링 중심 |
| 자기장계 | 미정 | yaw 절대방향 보조 | 초기 우선순위 낮음 |
| 하방 거리센서 | ToF/LiDAR 미정 | 저고도 유지 실험 | 고도 유지 목표 시 기압계보다 중요 |
| 전원 분배 | PDB 또는 직접 분배 | 배터리 전원 ESC 4개로 분배 | 쇼트 체크 필수 |

### Stage 2. 실기체 확장 후보

| 구분 | 부품 | 역할 | 비고 |
| --- | --- | --- | --- |
| FC | Kakute H7 Mini | 실제 비행용 H7 FC | Betaflight/PX4/ArduPilot 검토 |
| Companion | Raspberry Pi | 영상/AI/장애물 판단 | 별도 5V BEC/UBEC 권장 |
| 통신 | UART 또는 USB | FC와 Pi 연결 | MAVLink 우선 검토 |
| 센서 | 카메라, ToF, LiDAR 등 | 장애물 감지 | Pi에서 처리 |

## 저장소 구조

```text
project-drone/
├── 3d-models/             # 기체 프레임 및 마운트 모델
├── docs/                  # 설계 문서 및 참고 자료
│   ├── mb1364-h723zg-e01_schematic.pdf
│   ├── stm32h723zg.pdf
│   └── planned-docs/      # safety, wiring, ESC test, IMU bring-up 등 작성 예정
├── firmware/
│   └── Drone/             # STM32H723 학습용 FC 펌웨어
├── hardware/              # 회로, 배선, 전원 분배 자료
├── logs/                  # 센서/모터/제어 테스트 로그 작성 예정
└── README.md
```

## 개발 로드맵

### STEP 0. 안전 및 기본 개념

전원, 배터리, ESC, 모터, 프로펠러의 위험을 이해하고 안전 절차를 먼저 정의합니다.

- [ ] LiPo 배터리 안전 수칙 정리
- [ ] XT60 커넥터 극성 확인 방법 정리
- [ ] 멀티미터 사용법 정리
- [ ] 배터리 연결 전 쇼트 체크 절차 작성
- [ ] 프롭 제거 상태에서만 모터 테스트하는 규칙 작성
- [ ] 비상 정지 절차 작성
- [ ] 작업 공간 안전 기준 작성
- [ ] 모터 테스트용 고정 지그 또는 고정 장치 준비
- [ ] smoke stopper 사용 여부 결정

완료 기준:

- 배터리 연결 전 전원 라인 쇼트 여부를 확인할 수 있습니다.
- 모터 테스트 시 프로펠러를 장착하지 않습니다.
- 이상 상황에서 즉시 전원을 차단할 수 있습니다.

### STEP 1. 부품 확인 및 데이터시트 정리

각 부품의 전원, 신호 방식, 연결 방식을 정리합니다.

- [x] 부품 수량 및 모델명 확인: STM32H723 보드, 모터 4개, ESC 4개, IMU, 기압계
- [ ] STM32H723 Nucleo 정확한 모델명 기록
- [ ] STM32 보드의 3.3V/5V 전원 공급 가능 범위 확인
- [ ] MPU-6500 전원 전압 및 SPI/I2C 연결 방식 확인
- [ ] BMP388 전원 전압 및 SPI/I2C 연결 방식 확인
- [ ] BLHeli_S 30A ESC의 입력 신호 방식 확인: PWM, OneShot, DSHOT
- [ ] RS2205 2300KV 모터 권장 배터리/프롭 확인
- [ ] 배터리 셀 수 결정: 3S 또는 4S
- [ ] 전류 소모 예상치 계산
- [ ] 배선 굵기 및 커넥터 종류 정리

산출물:

- [ ] `docs/parts-list.md`
- [ ] `docs/power-budget.md`
- [ ] `docs/wiring.md`

완료 기준:

- 각 부품의 전원 전압과 연결 방식을 문서화했습니다.
- ESC 4개와 모터 4개의 연결 구조를 설명할 수 있습니다.

### STEP 2. 전원계 및 개별 ESC 배선 설계

개별 ESC 4개를 안전하게 전원 분배하고, STM32H723에서 각 ESC에 독립적인 신호를 보낼 수 있게 설계합니다.

```text
STM32 TIMx_CH1 -> ESC1 signal -> Motor1
STM32 TIMx_CH2 -> ESC2 signal -> Motor2
STM32 TIMx_CH3 -> ESC3 signal -> Motor3
STM32 TIMx_CH4 -> ESC4 signal -> Motor4

Battery + -> PDB/direct split -> ESC1/2/3/4 +
Battery - -> PDB/direct split -> ESC1/2/3/4 -
STM32 GND <-> ESC signal GND common
```

- [ ] PDB 사용 여부 결정
- [ ] 배터리 메인 파워 배선 규격 결정: 14AWG 이상 검토
- [ ] ESC 4개 전원 분배 방식 설계
- [ ] ESC 신호선과 GND 연결 규칙 정리
- [ ] STM32와 ESC GND 공통 연결 확인
- [ ] 라즈베리파이 전원은 별도 5V BEC/UBEC 사용 검토
- [ ] 배터리 연결 전 쇼트 체크 절차 문서화
- [ ] 전원 투입 순서 문서화

완료 기준:

- ESC 4개에 전원이 안전하게 분배되는 구조가 정리되었습니다.
- STM32와 ESC의 신호 GND 공통 연결 원칙을 문서화했습니다.

### STEP 3. ESC 및 모터 단독 테스트

프롭을 제거한 상태에서 ESC와 모터를 하나씩 안전하게 구동합니다.

- [ ] ESC 1개만 연결하여 PWM 신호 테스트
- [ ] PWM 1000us, 1500us, 2000us 출력 테스트
- [ ] ESC arm/min/max 반응 확인
- [ ] 모터 1개 회전 시작점 확인
- [ ] 모터 회전 방향 확인
- [ ] 모터/ESC 발열 확인
- [ ] 이상 진동 확인
- [ ] 같은 절차를 ESC/모터 4개에 반복
- [ ] 모터 번호 지정: M1, M2, M3, M4
- [ ] X-frame 기준 모터 위치와 회전 방향 기록

완료 기준:

- 프롭 없는 상태에서 모터 4개가 모두 개별적으로 정상 반응합니다.
- 각 모터의 번호, 위치, 회전 방향이 기록되어 있습니다.

### STEP 4. 센서 Bring-up

MPU-6500과 BMP388의 기본 통신을 확인하고 원시 데이터를 안정적으로 읽습니다.

MPU-6500 체크리스트:

- [ ] SPI 또는 I2C 연결도 작성
- [ ] WHO_AM_I 값 읽기
- [ ] 자이로 raw x/y/z 출력
- [ ] 가속도 raw x/y/z 출력
- [ ] 샘플링 주기 측정
- [ ] 정지 상태 자이로 noise 측정
- [ ] 자이로 bias 측정
- [ ] 가속도 1g 방향 확인
- [ ] 센서 축과 기체 축 매핑 문서화

BMP388 체크리스트:

- [ ] Chip ID 읽기
- [ ] 온도 raw 출력
- [ ] 기압 raw 출력
- [ ] 고도 변환식 구현
- [ ] 정지 상태 노이즈 측정
- [ ] 스펀지 커버 전후 노이즈 비교

자기장계 체크리스트:

- [ ] 사용할 자기장계 후보 선정
- [ ] 자기장계는 초기 비행제어 필수 항목이 아님을 문서화
- [ ] 모터/전류/배터리 근처에서 자기장계 값이 흔들릴 수 있음을 기록

완료 기준:

- 정지 상태에서 IMU와 기압계 값이 안정적으로 출력됩니다.
- 센서 축 방향과 기체 축 방향이 문서화되었습니다.

### STEP 5. 자세 추정

IMU 원시값으로 roll, pitch 값을 추정합니다.

- [ ] 자이로 raw 값을 deg/s 또는 rad/s로 변환
- [ ] 가속도 raw 값을 g 또는 m/s²로 변환
- [ ] 자이로 bias 보정 구현
- [ ] 자이로 적분 기반 각도 변화 계산
- [ ] 가속도 기반 roll/pitch 계산
- [ ] Complementary Filter 구현
- [ ] 손으로 기울였을 때 roll/pitch 방향 확인
- [ ] 정지 상태 drift 확인
- [ ] 필터 alpha/cutoff 값 튜닝
- [ ] yaw는 자이로 적분만으로 drift가 발생함을 문서화

완료 기준:

- 기체를 손으로 기울이면 roll/pitch 값이 직관적인 방향으로 변합니다.
- 정지 상태에서 자세 추정값이 심하게 흔들리지 않습니다.

### STEP 6. 제어 이론 및 모터 믹싱

쿼드콥터가 roll, pitch, yaw, throttle을 어떻게 제어하는지 이해하고 모터 믹싱을 구현합니다.

학습 항목:

- [ ] 쿼드콥터 X-frame 모터 배치 이해
- [ ] CW/CCW 프로펠러 방향 이해
- [ ] roll 제어 원리 정리
- [ ] pitch 제어 원리 정리
- [ ] yaw 제어 원리 정리
- [ ] throttle과 고도 관계 정리
- [ ] Rate mode와 Angle mode 차이 정리
- [ ] PID의 P/I/D 역할 정리
- [ ] Betaflight의 gyro/filter/PID/mixer 구조 참고

구현 체크리스트:

- [ ] PID 구조체 구현
- [ ] dt 계산 구현
- [ ] P 제어만 먼저 테스트
- [ ] I term 제한 구현
- [ ] D term 필터링 구현
- [ ] PID 출력 제한 구현
- [ ] X-frame motor mixing 구현
- [ ] arm/disarm 상태 구현
- [ ] throttle cut 구현
- [ ] 모터 최소/최대 출력 제한 구현

산출물:

- [ ] `docs/control-basics.md`
- [ ] `docs/pid.md`
- [ ] `docs/motor-mixing.md`

완료 기준:

- roll/pitch/yaw 명령이 각 모터 출력에 어떻게 반영되는지 설명할 수 있습니다.
- 모터 믹싱 결과를 로그로 확인할 수 있습니다.

### STEP 7. 프롭 없는 통합 테스트

센서, 자세 추정, PID, 모터 믹싱, ESC 출력이 하나의 루프로 동작하는지 확인합니다.

- [ ] 1kHz 또는 목표 제어 루프 주기 설정
- [ ] loop time jitter 측정
- [ ] IMU read -> attitude estimate -> PID -> mixer -> motor output 흐름 구현
- [ ] 프롭 없는 상태에서 arm/disarm 테스트
- [ ] 기체를 손으로 roll 방향으로 기울였을 때 복원 방향 모터 출력 증가 확인
- [ ] 기체를 손으로 pitch 방향으로 기울였을 때 복원 방향 모터 출력 증가 확인
- [ ] 제어 방향이 반대가 아닌지 확인
- [ ] failsafe timeout 구현
- [ ] 비정상 센서값 감지 시 motor cut 구현

완료 기준:

- 프롭 없는 상태에서 기체 자세 변화에 따른 모터 보정 방향이 올바릅니다.
- arm/disarm과 failsafe가 확실히 동작합니다.

### STEP 8. 고정 지그 테스트

실제 자유비행 전에 고정 지그에서 1축/2축 자세 안정화를 검증합니다.

- [ ] 1축 roll 테스트 지그 준비
- [ ] roll PID 방향 확인
- [ ] roll PID gain 변화에 따른 반응 기록
- [ ] 2축 roll/pitch 테스트 지그 준비
- [ ] pitch PID 방향 확인
- [ ] 출력 포화 여부 확인
- [ ] 진동 로그 기록
- [ ] 이상 반응 시 즉시 disarm 절차 확인

완료 기준:

- 1축 지그에서 roll 복원 제어가 정상 동작합니다.
- 2축 지그에서 roll/pitch 복원 제어가 정상 동작합니다.
- PID 튜닝 변화가 로그로 기록됩니다.

### STEP 9. 고도 센서 및 제한적 고도 제어

기압계와 하방 거리센서를 이용해 고도 추정과 제한적 고도 제어를 실험합니다.

- [ ] BMP388 기압 기반 고도값 필터링
- [ ] 하방 ToF/LiDAR 센서 후보 선정
- [ ] 하방 거리센서 raw 값 읽기
- [ ] 거리센서 노이즈 측정
- [ ] 고도 오차 계산: target_altitude - current_altitude
- [ ] altitude PID 구현
- [ ] altitude PID 출력이 throttle 보정으로 연결되도록 구현
- [ ] 지그 또는 제한된 환경에서 throttle 보정 반응 확인

완료 기준:

- 고도 센서값을 안정적으로 읽고 필터링할 수 있습니다.
- 목표 고도와 현재 고도의 오차를 throttle 보정값으로 변환할 수 있습니다.
- 실제 자유비행 전 단계에서 고도 제어 흐름을 로그로 검증했습니다.

### STEP 10. Kakute H7 Mini 실기체 구성 검토

H723 학습 내용을 바탕으로 상용 H7 FC를 이용한 실제 드론 구성을 준비합니다.

- [ ] Kakute H7 Mini pinout 확인
- [ ] 개별 ESC 4개 사용 가능 여부 확인: M1~M4 signal pad 또는 커넥터 활용
- [ ] Betaflight 지원 여부 확인
- [ ] PX4 지원 버전 확인
- [ ] ArduPilot 지원 여부 확인
- [ ] UART 포트 수와 Raspberry Pi 연결 포트 선정
- [ ] FC 전원과 Raspberry Pi 전원 분리 설계
- [ ] GPS/자기장계 추가 여부 검토
- [ ] 실제 비행 전 상용 FC 설정 절차 문서화
- [ ] 프레임 크기 결정: RS2205 + 5045 프롭 기준, 225mm 전후
- [ ] Arm 및 메인 플레이트 설계
- [ ] 배터리 위치와 무게중심(CG) 검토
- [ ] 카메라 및 Raspberry Pi 마운트 공간 검토

완료 기준:

- Kakute H7 Mini를 어떤 펌웨어로 운용할지 결정했습니다.
- 개별 ESC 4개 연결 방식과 Raspberry Pi 연결 방식이 정리되었습니다.
- 실기체 프레임, 전장 배치, 무게중심 기준이 정리되었습니다.

### STEP 11. Raspberry Pi Companion 확장

Raspberry Pi가 고수준 판단을 담당하고 FC가 실시간 제어를 담당하는 구조를 구현합니다.

| 기능 | 담당 |
| --- | --- |
| 모터 출력 | FC |
| 자세 안정화 | FC |
| 센서 융합 | FC |
| failsafe | FC |
| 영상 처리 | Raspberry Pi |
| 라이다/ToF 처리 | Raspberry Pi |
| 장애물 판단 | Raspberry Pi |
| 경로 계획 | Raspberry Pi |
| AI 추론 | Raspberry Pi |

통신 체크리스트:

- [ ] UART 또는 USB 연결 방식 결정
- [ ] GND 공통 연결 규칙 정리
- [ ] FC -> Pi 상태 패킷 수신
- [ ] Pi -> FC 목표값 패킷 전송
- [ ] MAVLink 사용 여부 결정
- [ ] sequence number 구현 또는 MAVLink sequence 확인
- [ ] timeout failsafe 정의
- [ ] Pi 통신 끊김 시 FC 동작 정의
- [ ] GStreamer 또는 FFmpeg 기반 영상 스트리밍
- [ ] OpenCV 기반 객체 추적 및 장애물 감지
- [ ] 비행 로그 시각화 및 텔레메트리 대시보드 구성

명령 원칙:

Raspberry Pi는 모터 출력을 직접 보내지 않습니다.

비추천:

```text
motor1, motor2, motor3, motor4
```

추천:

```text
target_roll
target_pitch
target_yaw_rate
target_altitude
target_velocity
target_position
mode
```

완료 기준:

- Raspberry Pi가 꺼지거나 통신이 끊겨도 FC가 안전 상태로 진입합니다.
- Raspberry Pi는 목표값만 전달하고, 실제 모터 출력은 FC가 계산합니다.

### STEP 12. 장애물 감지 및 회피 실험

Raspberry Pi에서 주변 장애물을 감지하고 FC에 회피 목표값을 전달합니다.

- [ ] 전방 거리센서 또는 카메라 입력 구성
- [ ] 전방 장애물 거리 기준 정의
- [ ] 좌/우 회피 방향 판단 로직 구현
- [ ] 저속에서 정지 명령 테스트
- [ ] 목표 속도 명령 생성
- [ ] FC에 목표 속도 또는 목표 자세 명령 전송
- [ ] 장애물 감지 실패 시 안전 동작 정의
- [ ] 수동 조종권 회수 절차 정의

초기 회피 규칙 예시:

```text
if front_distance < safe_distance:
    forward_velocity = 0
    if left_distance > right_distance:
        lateral_velocity = left
    else:
        lateral_velocity = right
```

완료 기준:

- 전방 장애물을 감지하면 정지 또는 회피 명령을 생성합니다.
- 회피 판단은 FC의 모터 직접제어가 아니라 목표값 명령으로 전달됩니다.

## 펌웨어 구현 방향

H723 학습용 펌웨어는 Betaflight 전체 포팅이 아니라, Betaflight의 구조를 참고하여 작은 모듈로 직접 구현합니다.

```text
Betaflight gyro driver 구조 참고     -> 내 MPU-6500 드라이버 작성
Betaflight filter 구조 참고          -> 내 low pass filter 작성
Betaflight PID 구조 참고             -> 내 pid.c 작성
Betaflight mixer 구조 참고           -> 내 mixer.c 작성
Betaflight arming/failsafe 구조 참고 -> 내 state_machine.c 작성
```

### 초기 펌웨어 구조 예시

```text
firmware/Drone/
├── Core/
├── Drivers/
│   ├── imu/
│   │   ├── mpu6500.c
│   │   └── mpu6500.h
│   ├── baro/
│   │   ├── bmp388.c
│   │   └── bmp388.h
│   ├── mag/
│   │   └── README.md
│   └── esc/
│       ├── esc_pwm.c
│       └── esc_pwm.h
├── Flight/
│   ├── attitude.c
│   ├── pid.c
│   ├── mixer.c
│   ├── altitude.c
│   └── failsafe.c
├── App/
│   ├── main_loop.c
│   └── telemetry.c
└── README.md
```

### 기본 루프 예시

```c
while (1) {
    read_imu();
    estimate_attitude();
    run_rate_pid();
    mix_motors();
    write_motor_outputs();
    check_failsafe();
    send_telemetry();
}
```

고도 제어가 추가된 이후:

```c
while (1) {
    read_imu();
    read_altitude_sensor();

    estimate_attitude();
    estimate_altitude();

    run_altitude_pid();
    run_angle_pid();
    run_rate_pid();

    mix_motors();
    write_motor_outputs();

    check_failsafe();
    send_telemetry();
}
```

## 현재 결정된 사항

- 1차 학습 보드는 STM32H723 Nucleo를 사용합니다.
- ESC는 4-in-1이 아니라 개별 BLHeli_S 30A ESC 4개를 사용합니다.
- H723 단계에서는 실제 자유비행보다 책상 위 검증, 프롭 없는 테스트, 고정 지그 안정화를 우선합니다.
- Betaflight는 그대로 포팅하기보다 구조와 개념을 참고합니다.
- 실기체 확장 후보는 Kakute H7 Mini입니다.
- Raspberry Pi는 companion computer로 사용하며 모터 직접제어를 하지 않습니다.

## 아직 결정되지 않은 사항

- 배터리 셀 수: 3S 또는 4S
- 프로펠러 크기
- ESC 신호 방식: 초기 PWM, 이후 DSHOT 검토
- H723 단계에서 사용할 하방 ToF/LiDAR 센서
- 자기장계 모델
- Kakute H7 Mini에서 사용할 펌웨어: Betaflight, PX4, ArduPilot
- Raspberry Pi와 FC 통신 방식: UART, USB, MAVLink
- 실제 비행용 프레임 크기와 무게중심 설계

## 참고 메모

- 모터 테스트 시에는 반드시 프로펠러를 제거합니다.
- 배터리 연결 전 멀티미터로 전원 라인 쇼트 여부를 확인합니다.
- STM32와 ESC의 신호 GND는 반드시 공통으로 연결합니다.
- 첫 비행 전 failsafe와 arm/disarm 동작을 먼저 검증합니다.
- H723 단계의 목표는 자유비행이 아니라 비행제어 핵심 원리 학습입니다.
- 고도 유지는 기압계만으로는 어렵기 때문에 하방 ToF/LiDAR 추가를 우선 검토합니다.

## 블로그

프로젝트 진행 기록을 단계별로 정리할 예정입니다.

추천 블로그 글 순서:

1. 프로젝트 목표와 개발 전략
2. STM32H723 Nucleo를 학습용 FC로 선택한 이유
3. 개별 ESC 4개 구조와 전원 분배
4. MPU-6500 bring-up
5. BMP388 bring-up
6. 자세 추정 구현
7. PID와 모터 믹싱
8. 프롭 없는 통합 테스트
9. 고정 지그 안정화
10. Kakute H7 Mini와 Raspberry Pi 확장 계획
