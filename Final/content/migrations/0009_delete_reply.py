# Generated by Django 4.2.3 on 2023-08-10 06:42

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('content', '0008_delete_bookmark'),
    ]

    operations = [
        migrations.DeleteModel(
            name='Reply',
        ),
    ]