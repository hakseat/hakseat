from django.shortcuts import render

# Create your views here.
from uuid import uuid4
from django.shortcuts import render
from rest_framework.response import Response
from rest_framework.views import APIView

class Index(APIView):
    def get(self,request):
        return render(request, 'final/index.html')
    #난향
class Index1(APIView):
    def get(self,request):
        return render(request, 'final/index1.html')
    #수정

class Index3(APIView):
    def get(self, request):
        return render(request, 'final/index3.html')
    #운정



