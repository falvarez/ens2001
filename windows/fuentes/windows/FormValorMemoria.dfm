object frmValorMemoria: TfrmValorMemoria
  Left = 240
  Top = 237
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  Caption = 'Editar Memoria'
  ClientHeight = 73
  ClientWidth = 112
  Color = clBtnFace
  Constraints.MaxHeight = 100
  Constraints.MaxWidth = 120
  Constraints.MinHeight = 100
  Constraints.MinWidth = 120
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnKeyDown = LeerTecla
  OnShow = Mostrar
  PixelsPerInch = 96
  TextHeight = 13
  object lblDireccion: TLabel
    Left = 11
    Top = 10
    Width = 16
    Height = 13
    Caption = 'RO'
  end
  object btnAceptar: TButton
    Left = 32
    Top = 40
    Width = 49
    Height = 25
    Caption = '&Aceptar'
    Default = True
    TabOrder = 0
    OnClick = BotonAceptarClick
    OnKeyDown = LeerTecla
  end
  object txtMemoria: TEdit
    Left = 48
    Top = 8
    Width = 49
    Height = 21
    TabOrder = 1
    OnKeyDown = LeerTecla
  end
end
