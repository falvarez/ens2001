object frmRegistros: TfrmRegistros
  Left = 259
  Top = 177
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  Caption = 'Ens2001-Registros'
  ClientHeight = 403
  ClientWidth = 162
  Color = clBtnFace
  Constraints.MaxHeight = 430
  Constraints.MaxWidth = 170
  Constraints.MinHeight = 430
  Constraints.MinWidth = 170
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = Cerrar
  OnHide = Ocultar
  OnPaint = Actualizar
  OnShow = Mostrar
  PixelsPerInch = 96
  TextHeight = 13
  object grpRegistros: TGroupBox
    Left = 6
    Top = 9
    Width = 153
    Height = 225
    Caption = 'Banco de Registros'
    TabOrder = 0
    object lblRegA: TLabel
      Left = 10
      Top = 23
      Width = 13
      Height = 13
      Caption = '  A'
      OnDblClick = EditarRegistroA
    end
    object lblRegR0: TLabel
      Left = 8
      Top = 40
      Width = 14
      Height = 13
      Caption = 'R0'
      OnDblClick = EditarRegistroR0
    end
    object lblRegR1: TLabel
      Left = 8
      Top = 56
      Width = 14
      Height = 13
      Caption = 'R1'
      OnDblClick = EditarRegistroR1
    end
    object lblRegR2: TLabel
      Left = 8
      Top = 72
      Width = 14
      Height = 13
      Caption = 'R2'
      OnDblClick = EditarRegistroR2
    end
    object lblRegR3: TLabel
      Left = 8
      Top = 88
      Width = 14
      Height = 13
      Caption = 'R3'
      OnDblClick = EditarRegistroR3
    end
    object lblRegR5: TLabel
      Left = 8
      Top = 120
      Width = 14
      Height = 13
      Caption = 'R5'
      OnDblClick = EditarRegistroR5
    end
    object lblRegR4: TLabel
      Left = 8
      Top = 104
      Width = 14
      Height = 13
      Caption = 'R4'
      OnDblClick = EditarRegistroR4
    end
    object lblRegR6: TLabel
      Left = 8
      Top = 136
      Width = 14
      Height = 13
      Caption = 'R6'
      OnDblClick = EditarRegistroR6
    end
    object lblRegR7: TLabel
      Left = 80
      Top = 24
      Width = 14
      Height = 13
      Caption = 'R7'
      OnDblClick = EditarRegistroR7
    end
    object lblRegR8: TLabel
      Left = 80
      Top = 40
      Width = 14
      Height = 13
      Caption = 'R8'
      OnDblClick = EditarRegistroR8
    end
    object lblRegR9: TLabel
      Left = 80
      Top = 56
      Width = 14
      Height = 13
      Caption = 'R9'
      OnDblClick = EditarRegistroR9
    end
    object lblRegPC: TLabel
      Left = 80
      Top = 72
      Width = 14
      Height = 13
      Caption = 'PC'
      OnDblClick = EditarRegistroPC
    end
    object lblRegSP: TLabel
      Left = 80
      Top = 88
      Width = 14
      Height = 13
      Caption = 'SP'
      OnDblClick = EditarRegistroSP
    end
    object lblRegIX: TLabel
      Left = 80
      Top = 104
      Width = 10
      Height = 13
      Caption = 'IX'
      OnDblClick = EditarRegistroIX
    end
    object lblRegIY: TLabel
      Left = 80
      Top = 120
      Width = 10
      Height = 13
      Caption = 'IY'
      OnDblClick = EditarRegistroIY
    end
    object lblRegSR: TLabel
      Left = 80
      Top = 136
      Width = 15
      Height = 13
      Caption = 'SR'
      OnDblClick = EditarRegistroSR
    end
    object txtRegA: TEdit
      Left = 32
      Top = 22
      Width = 41
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 20
      OnDblClick = EditarRegistroA
      OnKeyDown = LeerTecla
    end
    object GroupBox1: TGroupBox
      Left = 8
      Top = 160
      Width = 137
      Height = 57
      Caption = 'Biestables'
      TabOrder = 0
      object lblBSZ: TLabel
        Left = 8
        Top = 16
        Width = 7
        Height = 13
        Hint = 'Biestable Cero'
        Caption = 'Z'
        ParentShowHint = False
        ShowHint = True
      end
      object lblBS: TLabel
        Left = 8
        Top = 32
        Width = 7
        Height = 13
        Hint = 'Biestable Signo'
        Caption = 'S'
        ParentShowHint = False
        ShowHint = True
      end
      object lblBSP: TLabel
        Left = 56
        Top = 16
        Width = 7
        Height = 13
        Hint = 'Biestable Paridad'
        Caption = 'P'
        ParentShowHint = False
        ShowHint = True
      end
      object lblBSC: TLabel
        Left = 96
        Top = 16
        Width = 7
        Height = 13
        Hint = 'Biestable Acarreo'
        Caption = 'C'
        ParentShowHint = False
        ShowHint = True
      end
      object lblBSV: TLabel
        Left = 56
        Top = 32
        Width = 7
        Height = 13
        Hint = 'Biestable Desbordamiento'
        Caption = 'V'
        ParentShowHint = False
        ShowHint = True
      end
      object Label5: TLabel
        Left = 96
        Top = 32
        Width = 8
        Height = 13
        Hint = 'Biestable Fin de Programa'
        Caption = 'H'
        ParentShowHint = False
        ShowHint = True
      end
    end
    object txtRegR0: TEdit
      Left = 32
      Top = 38
      Width = 41
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 1
      OnDblClick = EditarRegistroR0
      OnKeyDown = LeerTecla
    end
    object txtRegR1: TEdit
      Left = 32
      Top = 54
      Width = 41
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 2
      OnDblClick = EditarRegistroR1
      OnKeyDown = LeerTecla
    end
    object txtRegR2: TEdit
      Left = 32
      Top = 70
      Width = 41
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 3
      OnDblClick = EditarRegistroR2
      OnKeyDown = LeerTecla
    end
    object txtRegR3: TEdit
      Left = 32
      Top = 86
      Width = 41
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 4
      OnDblClick = EditarRegistroR3
      OnKeyDown = LeerTecla
    end
    object txtRegR4: TEdit
      Left = 32
      Top = 102
      Width = 41
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 5
      OnDblClick = EditarRegistroR4
      OnKeyDown = LeerTecla
    end
    object txtRegR5: TEdit
      Left = 32
      Top = 118
      Width = 41
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 6
      OnDblClick = EditarRegistroR5
      OnKeyDown = LeerTecla
    end
    object txtRegR6: TEdit
      Left = 32
      Top = 134
      Width = 41
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 7
      OnDblClick = EditarRegistroR6
      OnKeyDown = LeerTecla
    end
    object txtRegR7: TEdit
      Left = 102
      Top = 22
      Width = 43
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 8
      OnDblClick = EditarRegistroR7
      OnKeyDown = LeerTecla
    end
    object txtRegR8: TEdit
      Left = 102
      Top = 38
      Width = 43
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 9
      OnDblClick = EditarRegistroR8
      OnKeyDown = LeerTecla
    end
    object txtRegR9: TEdit
      Left = 102
      Top = 54
      Width = 43
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 10
      OnDblClick = EditarRegistroR9
      OnKeyDown = LeerTecla
    end
    object txtRegPC: TEdit
      Left = 102
      Top = 70
      Width = 43
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 11
      OnDblClick = EditarRegistroPC
      OnKeyDown = LeerTecla
    end
    object txtRegSP: TEdit
      Left = 102
      Top = 86
      Width = 43
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 12
      OnDblClick = EditarRegistroSP
      OnKeyDown = LeerTecla
    end
    object txtRegIX: TEdit
      Left = 102
      Top = 102
      Width = 43
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 13
      OnDblClick = EditarRegistroIX
      OnKeyDown = LeerTecla
    end
    object txtRegIY: TEdit
      Left = 102
      Top = 118
      Width = 43
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 14
      OnDblClick = EditarRegistroIY
      OnKeyDown = LeerTecla
    end
    object txtRegSR: TEdit
      Left = 102
      Top = 134
      Width = 43
      Height = 17
      AutoSize = False
      ReadOnly = True
      TabOrder = 15
      OnDblClick = EditarRegistroSR
      OnKeyDown = LeerTecla
    end
    object txtBSZ: TEdit
      Left = 30
      Top = 174
      Width = 19
      Height = 17
      Hint = 'Biestable Cero'
      AutoSize = False
      ParentShowHint = False
      ReadOnly = True
      ShowHint = True
      TabOrder = 16
      OnKeyDown = LeerTecla
    end
    object txtBSS: TEdit
      Left = 30
      Top = 190
      Width = 19
      Height = 17
      Hint = 'Biestable Signo'
      AutoSize = False
      ParentShowHint = False
      ReadOnly = True
      ShowHint = True
      TabOrder = 17
      OnKeyDown = LeerTecla
    end
    object txtBSP: TEdit
      Left = 78
      Top = 174
      Width = 19
      Height = 17
      Hint = 'Biestable Paridad'
      AutoSize = False
      ParentShowHint = False
      ReadOnly = True
      ShowHint = True
      TabOrder = 18
      OnKeyDown = LeerTecla
    end
    object txtBSV: TEdit
      Left = 78
      Top = 190
      Width = 19
      Height = 17
      Hint = 'Biestable Desbordamiento'
      AutoSize = False
      ParentShowHint = False
      ReadOnly = True
      ShowHint = True
      TabOrder = 19
      OnKeyDown = LeerTecla
    end
    object txtBSC: TEdit
      Left = 118
      Top = 174
      Width = 19
      Height = 17
      Hint = 'Biestable Acarreo'
      AutoSize = False
      ParentShowHint = False
      ReadOnly = True
      ShowHint = True
      TabOrder = 21
      OnKeyDown = LeerTecla
    end
    object txtBSH: TEdit
      Left = 118
      Top = 190
      Width = 19
      Height = 17
      Hint = 'Biestable Fin de Programa'
      AutoSize = False
      ParentShowHint = False
      ReadOnly = True
      ShowHint = True
      TabOrder = 22
      OnKeyDown = LeerTecla
    end
  end
  object GroupBox3: TGroupBox
    Left = 6
    Top = 281
    Width = 65
    Height = 81
    Caption = 'Pila'
    TabOrder = 1
    object lblPila1: TLabel
      Left = 16
      Top = 32
      Width = 33
      Height = 13
      Caption = 'lblPila1'
    end
    object lblPila2: TLabel
      Left = 16
      Top = 64
      Width = 33
      Height = 13
      Caption = 'lblPila1'
    end
    object Label1: TLabel
      Left = 8
      Top = 16
      Width = 34
      Height = 13
      Caption = 'Desde:'
    end
    object Label4: TLabel
      Left = 8
      Top = 48
      Width = 31
      Height = 13
      Caption = 'Hasta:'
    end
  end
  object GroupBox4: TGroupBox
    Left = 92
    Top = 281
    Width = 65
    Height = 81
    Caption = 'Código'
    TabOrder = 2
    object lblCodigo1: TLabel
      Left = 16
      Top = 32
      Width = 33
      Height = 13
      Caption = 'lblPila1'
    end
    object lblCodigo2: TLabel
      Left = 16
      Top = 64
      Width = 33
      Height = 13
      Caption = 'lblPila1'
    end
    object Label2: TLabel
      Left = 8
      Top = 16
      Width = 34
      Height = 13
      Caption = 'Desde:'
    end
    object Label3: TLabel
      Left = 8
      Top = 48
      Width = 31
      Height = 13
      Caption = 'Hasta:'
    end
  end
  object btnReiniciar: TButton
    Left = 6
    Top = 375
    Width = 153
    Height = 25
    Caption = 'Reiniciar Valores'
    TabOrder = 3
    OnClick = BotonReiniciarClick
  end
  object GroupBox2: TGroupBox
    Left = 6
    Top = 241
    Width = 153
    Height = 37
    Caption = 'Siguiente Instrucción'
    TabOrder = 4
    object lblInstruccion: TLabel
      Left = 8
      Top = 16
      Width = 23
      Height = 13
      Caption = 'NOP'
    end
  end
end
