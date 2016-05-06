object frmConfiguracion: TfrmConfiguracion
  Left = 239
  Top = 96
  BorderIcons = [biMinimize]
  BorderStyle = bsToolWindow
  Caption = 'Ens2001-Configuración'
  ClientHeight = 413
  ClientWidth = 272
  Color = clBtnFace
  Constraints.MaxHeight = 447
  Constraints.MaxWidth = 280
  Constraints.MinHeight = 440
  Constraints.MinWidth = 280
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnKeyDown = LeerTecla
  OnShow = MostrarConfiguracion
  PixelsPerInch = 96
  TextHeight = 13
  object rdgBaseRepresentacion: TRadioGroup
    Left = 16
    Top = 10
    Width = 241
    Height = 57
    Caption = '&Base de Representación Numérica'
    ItemIndex = 0
    Items.Strings = (
      'Base 10 (&decimal)'
      'Base 16 (&hexadecimal)')
    TabOrder = 0
  end
  object rdgModoPila: TRadioGroup
    Left = 16
    Top = 74
    Width = 241
    Height = 57
    Caption = '&Dirección de Crecimiento de la Pila'
    ItemIndex = 1
    Items.Strings = (
      'Direcciones &Ascendentes'
      'Direcciones &Descendentes')
    TabOrder = 1
  end
  object rdgModoDepuracion: TRadioGroup
    Left = 16
    Top = 138
    Width = 241
    Height = 41
    Caption = '&Modo de Depuración'
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      'Sí'
      'No')
    TabOrder = 2
  end
  object rdgModoEjecucion: TRadioGroup
    Left = 16
    Top = 186
    Width = 241
    Height = 41
    Caption = '&Ejecución Paso a Paso'
    Columns = 2
    ItemIndex = 1
    Items.Strings = (
      'Sí'
      'No')
    TabOrder = 3
  end
  object rdgComprobarPC: TRadioGroup
    Left = 16
    Top = 234
    Width = 241
    Height = 41
    Caption = 'Comprobar si &PC invade el espacio de Pila'
    Columns = 2
    ItemIndex = 1
    Items.Strings = (
      'Sí'
      'No')
    TabOrder = 4
  end
  object rdgComprobarPila: TRadioGroup
    Left = 16
    Top = 282
    Width = 241
    Height = 41
    Caption = 'Comprobar si &SP invade el espacio de Código'
    Columns = 2
    ItemIndex = 1
    Items.Strings = (
      'Sí'
      'No')
    TabOrder = 5
  end
  object rdgResetearRegistros: TRadioGroup
    Left = 16
    Top = 330
    Width = 241
    Height = 41
    Caption = '&Inicializar los Registros al Ejecutar'
    Columns = 2
    ItemIndex = 0
    Items.Strings = (
      'Sí'
      'No')
    TabOrder = 6
  end
  object btnAceptar: TButton
    Left = 15
    Top = 378
    Width = 80
    Height = 25
    Caption = '&Aceptar'
    Default = True
    TabOrder = 7
    OnClick = BotonAceptarClick
    OnKeyDown = LeerTecla
  end
  object btnCancelar: TButton
    Left = 177
    Top = 378
    Width = 80
    Height = 25
    Cancel = True
    Caption = '&Cancelar'
    TabOrder = 8
    OnClick = BotonCancelarClick
    OnKeyDown = LeerTecla
  end
end
