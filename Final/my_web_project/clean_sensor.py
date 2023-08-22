import openpyxl
import csv
import time


def excel_to_csv(excel_file, csv_file):
    # Excel 파일 열기
    wb = openpyxl.load_workbook(excel_file)

    # 첫 번째 시트 선택
    sheet = wb.active

    # CSV 파일 열기
    with open(csv_file, 'w', newline='', encoding='utf-8') as csvfile:
        csvwriter = csv.writer(csvfile)

        # 각 행을 읽어 CSV로 쓰기
        for row in sheet.iter_rows(values_only=True):
            csvwriter.writerow(row)

    print(f'{excel_file} 파일이 {csv_file}로 변환되었습니다.')


if __name__ == '__main__':
    excel_file = 'example.xlsx'  # Excel 파일 이름
    csv_file = 'output.csv'  # 저장할 CSV 파일 이름

    while True:
        excel_to_csv('PLX-DAQ-v2.11.xlsm', '../templates/final/censor2.csv')
        time.sleep(1)  # 60초마다 반복