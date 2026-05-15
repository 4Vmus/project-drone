# Project Instructions

## Language

- 모든 답변은 한국어로 한다.

## Naming Rules

### Function Names

- 함수명은 사람이 유지보수하기 쉽도록 직관적인 이름을 사용한다.
- 값을 계산하거나 도출하는 함수는 `calc_`로 시작한다.
  - 예: `calc_total_price`, `calc_distance`
- 장치 제어, 상태 변경, 파일 저장, 통신 요청 등 실제 행위를 수행하는 함수는 `func_`로 시작한다.
  - 예: `func_save_config`, `func_start_motor`
- 위 규칙으로 분류하기 애매한 함수는 임의로 확정하지 말고, 적절한 후보 이름과 이유를 사용자에게 알려 확인을 받는다.

### Variable Names

- 변수명은 사람이 유지보수하기 쉽도록 직관적인 이름을 사용한다.
- 임시 index 변수는 `i`, `j` 대신 기본적으로 `index_`로 시작한다.
  - 예: `index_item`, `index_layer`
- 함수 내부에서만 사용하는 주요 지역변수는 `local_`로 시작한다.
  - 예: `local_result`, `local_config`
- 전역변수는 `global_`로 시작한다.
  - 예: `global_state`, `global_database_path`
- 위 규칙으로 분류하기 애매한 변수는 적절한 후보 이름과 이유를 사용자에게 알려 확인을 받는다.

## Project Structure

- 프로젝트는 기본적으로 `Layer1`, `Layer2`, `Layer3`, `Layer4`, `Database` 폴더 구조를 따른다.
- Layer의 역할이 명확하지 않은 경우, 임의로 배치하지 말고 사용자에게 확인한다.

## Coding Style

- 코드는 사람이 유지/보수 할 수 있게, 직관적이나 사람에게 친화적으로 구성한다.
- 사용자가 요청하지 않은 대규모 리팩터링은 하지 않는다.
- 파일을 수정하기 전 관련 파일을 먼저 읽고 구조를 파악한다.
- 변경 후 실행 가능한 테스트나 검증 방법이 있으면 수행한다.
