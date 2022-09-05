object Form1: TForm1
  Left = 283
  Top = 40
  Width = 1194
  Height = 880
  BiDiMode = bdLeftToRight
  Caption = #1048#1052' ENGINE KAMAZ ('#1042#1077#1088#1089#1080#1103' 06)'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  ParentBiDiMode = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object L_ERROR_DATA: TLabel
    Left = 1320
    Top = 24
    Width = 193
    Height = 13
    Caption = #1054#1096#1080#1073#1082#1080' '#1087#1088#1080' '#1088#1072#1073#1086#1090#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object L_RX_DATA: TLabel
    Left = 960
    Top = 136
    Width = 112
    Height = 13
    Caption = #1055#1088#1080#1085#1103#1090#1099#1077' '#1076#1072#1085#1085#1099#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object L_TX_DATA: TLabel
    Left = 960
    Top = 24
    Width = 127
    Height = 13
    Caption = #1055#1077#1088#1077#1076#1072#1085#1085#1099#1077' '#1076#1072#1085#1085#1099#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object LCOMPORT: TLabel
    Left = 866
    Top = 12
    Width = 66
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1087#1086#1088#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object SHNETSV: TShape
    Left = 8
    Top = 798
    Width = 17
    Height = 17
    Pen.Color = clGray
    Pen.Width = 2
    Shape = stEllipse
  end
  object LabelDisableCommunication: TLabel
    Left = 32
    Top = 800
    Width = 94
    Height = 13
    Caption = #1053#1077#1090' '#1089#1074#1103#1079#1080' '#1089' '#1050#1055#1057#1053
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 827
    Width = 1186
    Height = 19
    Panels = <
      item
        Width = 500
      end
      item
        Width = 150
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object MError: TMemo
    Left = 1320
    Top = 40
    Width = 241
    Height = 73
    ScrollBars = ssVertical
    TabOrder = 1
    Visible = False
  end
  object M_IN_DATA: TMemo
    Left = 960
    Top = 152
    Width = 601
    Height = 81
    ScrollBars = ssVertical
    TabOrder = 2
    Visible = False
  end
  object BStart: TButton
    Left = 864
    Top = 56
    Width = 75
    Height = 25
    Caption = #1057#1090#1072#1088#1090
    TabOrder = 3
    OnClick = BStartClick
  end
  object BExit: TButton
    Left = 864
    Top = 88
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = BExitClick
  end
  object M_OUT_DATA: TMemo
    Left = 960
    Top = 40
    Width = 337
    Height = 89
    ScrollBars = ssVertical
    TabOrder = 5
    Visible = False
  end
  object COMPORT: TComboBox
    Left = 856
    Top = 28
    Width = 97
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 6
    Items.Strings = (
      'COM1'
      'COM2'
      'COM3'
      'COM4'
      'COM5'
      'COM6')
  end
  object PCZAPRSVU: TPageControl
    Left = 8
    Top = 8
    Width = 345
    Height = 345
    ActivePage = ZAPRSVU
    TabIndex = 0
    TabOrder = 7
    object ZAPRSVU: TTabSheet
      Caption = #1047#1072#1087#1088#1086#1089' '#1042#1059
      object LZPRVU_BYTE4_1: TLabel
        Left = 12
        Top = 151
        Width = 147
        Height = 13
        Caption = #1059#1089#1090#1072#1074#1082#1072' '#1087#1086' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1102
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LSAVE: TLabel
        Left = 277
        Top = 268
        Width = 54
        Height = 16
        Caption = #1047#1072#1087#1080#1089#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE4_2: TLabel
        Left = 16
        Top = 167
        Width = 105
        Height = 13
        Caption = #1074' '#1087#1088#1086#1084#1082#1086#1085#1090#1091#1088#1077', '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LSUE: TLabel
        Left = 12
        Top = 7
        Width = 80
        Height = 13
        Caption = #1050#1086#1084#1072#1085#1076#1099' '#1042#1059':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE6_1: TLabel
        Left = 12
        Top = 183
        Width = 148
        Height = 13
        Caption = #1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1087#1086' '#1085#1072#1087#1088#1103#1078'.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE6_2: TLabel
        Left = 16
        Top = 199
        Width = 87
        Height = 13
        Caption = #1079#1072#1088#1103#1076#1072' '#1040#1050#1041', '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE8_1: TLabel
        Left = 12
        Top = 215
        Width = 175
        Height = 13
        Caption = #1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1087#1086' '#1087#1088#1080#1088#1072#1097#1077#1085#1080#1102
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE8_2: TLabel
        Left = 16
        Top = 231
        Width = 117
        Height = 13
        Caption = #1090#1086#1082#1072' '#1079#1072#1088#1103#1076#1072' '#1040#1050#1041', '#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE9_1: TLabel
        Left = 12
        Top = 247
        Width = 126
        Height = 13
        Caption = #1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1087#1086' '#1090#1086#1082#1091
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE9_2: TLabel
        Left = 16
        Top = 263
        Width = 94
        Height = 13
        Caption = #1079#1072#1088#1103#1076#1082#1072' '#1040#1050#1041', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE11_1: TLabel
        Left = 12
        Top = 279
        Width = 126
        Height = 13
        Caption = #1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1087#1086' '#1090#1086#1082#1091
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LZPRVU_BYTE11_2: TLabel
        Left = 16
        Top = 295
        Width = 94
        Height = 13
        Caption = #1087#1088#1086#1084#1082#1086#1085#1090#1091#1088#1072', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object UpDown1: TUpDown
        Left = 249
        Top = 155
        Width = 16
        Height = 24
        Associate = E_UST_PROMCONTUR
        ArrowKeys = False
        Min = 0
        Max = 990
        Position = 540
        TabOrder = 0
        Thousands = False
        Wrap = False
      end
      object CheckListBoxChanel1: TCheckListBox
        Left = 8
        Top = 24
        Width = 209
        Height = 113
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        Items.Strings = (
          '7'#1088' - '#1056#1077#1079#1077#1088#1074
          '6'#1088' - '#1056#1077#1079#1077#1088#1074
          '5'#1088' - '#1056#1077#1079#1077#1088#1074
          '4'#1088' - '#1056#1077#1079#1077#1088#1074
          '3'#1088' - '#1057#1073#1088#1086#1089' '#1072#1074#1072#1088#1080#1080
          '2'#1088' - '#1047#1072#1088#1103#1076' '#1040#1050#1041
          '1'#1088' - '#1056#1072#1073#1086#1090#1072' '#1086#1090' '#1040#1050#1041
          '0'#1088' - '#1056#1072#1073#1086#1090#1072' '#1086#1090' '#1089#1077#1090#1080' 380 '#1042)
        ParentFont = False
        TabOrder = 1
      end
      object E_UST_PROMCONTUR: TEdit
        Left = 192
        Top = 155
        Width = 57
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        MaxLength = 3
        ParentFont = False
        TabOrder = 2
        Text = '540'
        OnChange = E_UST_PROMCONTURChange
        OnKeyPress = E_UST_PROMCONTURKeyPress
      end
      object CBSAVE: TCheckBox
        Left = 289
        Top = 288
        Width = 25
        Height = 17
        TabOrder = 3
      end
      object E_OGR_ZAR_AKB: TEdit
        Left = 192
        Top = 187
        Width = 57
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        MaxLength = 3
        ParentFont = False
        TabOrder = 4
        Text = '0'
        OnChange = E_OGR_ZAR_AKBChange
        OnKeyPress = E_UST_PROMCONTURKeyPress
      end
      object UpDown2: TUpDown
        Left = 249
        Top = 187
        Width = 16
        Height = 24
        Associate = E_OGR_ZAR_AKB
        ArrowKeys = False
        Min = 0
        Max = 990
        Position = 0
        TabOrder = 5
        Thousands = False
        Wrap = False
      end
      object E_OGR_PRIR_J_ZAR_AKB: TEdit
        Left = 192
        Top = 219
        Width = 57
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        MaxLength = 3
        ParentFont = False
        TabOrder = 6
        Text = '0'
        OnChange = E_OGR_PRIR_J_ZAR_AKBChange
        OnKeyPress = E_UST_PROMCONTURKeyPress
      end
      object UpDown3: TUpDown
        Left = 249
        Top = 219
        Width = 16
        Height = 24
        Associate = E_OGR_PRIR_J_ZAR_AKB
        ArrowKeys = False
        Min = 0
        Max = 990
        Position = 0
        TabOrder = 7
        Thousands = False
        Wrap = False
      end
      object E_OGR_J_ZAR_AKB: TEdit
        Left = 192
        Top = 251
        Width = 57
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        MaxLength = 3
        ParentFont = False
        TabOrder = 8
        Text = '0'
        OnChange = E_OGR_J_ZAR_AKBChange
        OnKeyPress = E_UST_PROMCONTURKeyPress
      end
      object UpDown4: TUpDown
        Left = 249
        Top = 251
        Width = 16
        Height = 24
        Associate = E_OGR_J_ZAR_AKB
        ArrowKeys = False
        Min = 0
        Max = 990
        Position = 0
        TabOrder = 9
        Thousands = False
        Wrap = False
      end
      object E_OGR_J_PROMCONTUR: TEdit
        Left = 192
        Top = 283
        Width = 57
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        MaxLength = 3
        ParentFont = False
        TabOrder = 10
        Text = '0'
        OnChange = E_OGR_J_PROMCONTURChange
        OnKeyPress = E_UST_PROMCONTURKeyPress
      end
      object UpDown5: TUpDown
        Left = 249
        Top = 283
        Width = 16
        Height = 24
        Associate = E_OGR_J_PROMCONTUR
        ArrowKeys = False
        Min = 0
        Max = 990
        Position = 0
        TabOrder = 11
        Thousands = False
        Wrap = False
      end
    end
  end
  object OTV_KPSN: TPageControl
    Left = 8
    Top = 360
    Width = 1153
    Height = 433
    ActivePage = OTV_KPSN_01h
    TabIndex = 0
    TabOrder = 8
    object OTV_KPSN_01h: TTabSheet
      Caption = #1054#1090#1074#1077#1090' '#1050#1055#1057#1053'1 ('#1082#1086#1084#1072#1085#1076#1072' 01h)'
      object LPCH1_BYTE3: TLabel
        Left = 56
        Top = 8
        Width = 188
        Height = 13
        Caption = 'Fpllout, '#1060#1040#1055#1063' '#1095#1072#1089#1090#1086#1090#1072' '#1089#1077#1090#1080', '#1043#1094
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE5: TLabel
        Left = 56
        Top = 32
        Width = 256
        Height = 13
        Caption = 'Dout RMS, '#1057#1050#1047' '#1082#1086#1101#1092#1092'. '#1084#1086#1076#1091#1083#1103#1094#1080#1080' '#1064#1048#1052', %'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE7: TLabel
        Left = 56
        Top = 56
        Width = 157
        Height = 13
        Caption = 'Im_set, '#1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1090#1086#1082#1072', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE9: TLabel
        Left = 56
        Top = 80
        Width = 189
        Height = 13
        Caption = 'Te, '#1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1088#1072#1076#1080#1072#1090#1086#1088#1072', '#176#1057
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE10: TLabel
        Left = 56
        Top = 104
        Width = 217
        Height = 13
        Caption = 'Tecu, '#1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1082#1086#1085#1090#1088#1086#1083#1083#1077#1088#1072', '#176#1057
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE13: TLabel
        Left = 392
        Top = 8
        Width = 366
        Height = 13
        Caption = 'Dchop, '#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1072' '#1084#1086#1076#1091#1083#1103#1094#1080#1080' '#1064#1048#1052' '#1090#1086#1088#1084#1086#1079#1085#1086#1075#1086' '#1082#1083#1102#1095#1072', %'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE17: TLabel
        Left = 392
        Top = 32
        Width = 390
        Height = 13
        Caption = 'Id (Ibr_m), '#1057#1088#1077#1076#1085#1080#1081' '#1079#1072' '#1087#1077#1088#1080#1086#1076' '#1064#1048#1052' '#1090#1086#1082' '#1090#1086#1088#1084#1086#1079#1085#1086#1075#1086' '#1088#1077#1079#1080#1089#1090#1086#1088#1072', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE23: TLabel
        Left = 392
        Top = 56
        Width = 395
        Height = 13
        Caption = 'Uac RMS, '#1057#1050#1047' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' '#1089#1086' '#1089#1090#1086#1088#1086#1085#1099' '#1092#1072#1079#1099' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1103', '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE25: TLabel
        Left = 390
        Top = 80
        Width = 253
        Height = 13
        Caption = 'Ia (I2) RMS, '#1057#1050#1047' '#1090#1086#1082#1072' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1103', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE29: TLabel
        Left = 846
        Top = 8
        Width = 216
        Height = 13
        Caption = 'Udc, '#1053#1072#1087#1088#1103#1078#1077#1085#1080#1077' '#1082#1086#1085#1076#1077#1085#1089#1072#1090#1086#1088#1086#1074', '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE39: TLabel
        Left = 846
        Top = 32
        Width = 297
        Height = 13
        Caption = 'Uac, '#1052#1075#1085#1086#1074#1077#1085#1085#1086#1077' '#1079#1085'-'#1077' '#1085#1072#1087#1088#1103#1078'. '#1087#1077#1088#1074'. '#1086#1073#1084'. (HV), '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE41: TLabel
        Left = 846
        Top = 56
        Width = 213
        Height = 13
        Caption = 'Ia, '#1052#1075#1085#1086#1074#1077#1085#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1090#1086#1082#1072' Ia, '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE43: TLabel
        Left = 846
        Top = 80
        Width = 213
        Height = 13
        Caption = 'Ib, '#1052#1075#1085#1086#1074#1077#1085#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1090#1086#1082#1072' Ib, '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object GB_PCH1_BYTE31: TGroupBox
        Left = 8
        Top = 132
        Width = 329
        Height = 129
        Caption = 'RUNMODE, '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099', '#1084#1083'.'#1073'.'
        TabOrder = 0
        object CB_PCH1_BYTE31: TCheckListBox
          Left = 8
          Top = 16
          Width = 313
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' DISCH_ON, '#1054#1057' '#1087#1088#1080#1085#1091#1076'. '#1088#1072#1079#1088#1103#1076#1072' '#1076#1083#1103' '#1095#1086#1087#1087#1077#1088#1072
            '6'#1088' '#8211' LIM_PLL, '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1079#1072#1076#1072#1085#1080#1103' '#1095#1072#1089#1090#1086#1090#1099' VCO PLL'
            '5'#1088' '#8211' LIM_UDC, '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1056#1053
            '4'#1088' '#8211' LIM_IDQ, '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1056#1058' D '#1080#1083#1080' Q'
            '3'#1088' '#8211' FAULT, '#1086#1096#1080#1073#1082#1080' '#1074' '#1089#1090#1072#1090#1091#1089#1077
            '2'#1088' '#8211' ENA/nPRE, (1 = '#1088#1072#1073#1086#1090#1072', 0 = '#1086#1078#1080#1076#1072#1085#1080#1077')'
            '1'#1088' '#8211' RUNMODE1, '#1054#1057' '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099
            '0'#1088' '#8211' RUNMODE0, '#1054#1057' '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH1_BYTE32: TGroupBox
        Left = 8
        Top = 268
        Width = 329
        Height = 129
        Caption = 'RUNMODE, '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099', '#1089#1090'.'#1073'.'
        TabOrder = 1
        object CB_PCH1_BYTE32: TCheckListBox
          Left = 8
          Top = 16
          Width = 313
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '6'#1088' '#8211' SYNCED, '#1087#1088'. '#1089#1080#1085#1093#1088'. ('#1074#1089#1077#1075#1076#1072' = 1)'
            '5'#1088' '#8211' S_INDELT, '#1087#1088'. '#1089#1080#1085#1093#1088'. ('#1074#1089#1077#1075#1076#1072' = 1)'
            '4'#1088' '#8211' SYNCED_IN, '#1087#1088'. '#1089#1080#1085#1093#1088'. ('#1074#1089#1077#1075#1076#1072' = 1)'
            '3'#1088' '#8211' TTS_ERR, '#1087#1088'. '#1085#1077#1091#1076#1072#1095#1085#1086#1081' '#1087#1086#1087#1099#1090#1082#1072' '#1074#1082#1083#1102#1095#1077#1085#1080#1103
            '2'#1088' '#8211' LOCK, 1 - PLL '#1074' '#1088#1077#1078#1080#1084#1077' '#1079#1072#1093#1074#1072#1090#1072
            '1'#1088' '#8211' SEARCH, 1 - PLL '#1074' '#1088#1077#1078#1080#1084#1077' '#1087#1086#1080#1089#1082#1072
            '0'#1088' '#8211' PRESENT, 1 - '#1087#1088#1080#1079#1085#1072#1082' '#1085#1086#1088#1084#1099' '#1074#1093#1086#1076#1085#1086#1075#1086' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH1_BYTE33: TGroupBox
        Left = 344
        Top = 132
        Width = 289
        Height = 129
        Caption = 'STATUS, '#1041#1080#1090#1099' '#1086#1096#1080#1073#1086#1082', '#1084#1083'.'#1073'.'
        TabOrder = 2
        object CB_PCH1_BYTE33: TCheckListBox
          Left = 8
          Top = 16
          Width = 273
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' OVT, '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1077' '#1090#1077#1084#1087#1077#1088#1072#1090#1091#1088#1099
            '6'#1088' '#8211' OVC, '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1077' '#1090#1086#1082#1072' A/B, TTS error'
            '5'#1088' '#8211' TZ6, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( '#1074' '#1088#1077#1079#1077#1088#1074#1077' )'
            '4'#1088' '#8211' TZ5, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( '#1074' '#1088#1077#1079#1077#1088#1074#1077' )'
            '3'#1088' '#8211' TZ4, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( '#1074' '#1088#1077#1079#1077#1088#1074#1077' )'
            '2'#1088' '#8211' TZ3, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( 3 '#1087#1086#1083#1091#1084#1086#1089#1090' )'
            '1'#1088' '#8211' TZ2, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( 2 '#1087#1086#1083#1091#1084#1086#1089#1090' )'
            '0'#1088' '#8211' TZ1, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( 1 '#1087#1086#1083#1091#1084#1086#1089#1090' )')
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH1_BYTE34: TGroupBox
        Left = 344
        Top = 268
        Width = 289
        Height = 129
        Caption = 'STATUS, '#1041#1080#1090#1099' '#1086#1096#1080#1073#1086#1082', '#1089#1090'.'#1073'.'
        TabOrder = 3
        object CB_PCH1_BYTE34: TCheckListBox
          Left = 8
          Top = 16
          Width = 273
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' CONFERR, '#1086#1096#1080#1073#1082#1072' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1080
            '6'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '5'#1088' '#8211' FRAMCRC, '#1086#1096#1080#1073#1082#1072' '#1074' EEPROM'
            '4'#1088' '#8211' I2CNAK, '#1086#1096#1080#1073#1082#1072' '#1085#1072' '#1084#1072#1075'. I2C'
            '3'#1088' '#8211' NO_SYNC, '#1053#1077#1090' '#1089#1080#1085#1093#1088#1086#1087#1072#1082#1077#1090#1072
            '2'#1088' '#8211' PLL_ERR, '#1087#1077#1088#1077#1082#1083'. '#1074' '#1088#1077#1078#1080#1084' '#1089#1090#1072#1073#1080#1083#1080#1079#1072#1094#1080#1080' '#1073#1077#1079' PLL LOCK'
            '1'#1088' '#8211' OVC_BR, '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1077' '#1090#1086#1082#1072' C (chopper)'
            '0'#1088' '#8211' OVV, '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1077' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' DC')
          ParentFont = False
          TabOrder = 0
        end
      end
      object EPCH1_BYTE3: TEdit
        Left = 8
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 4
        Text = '0,0'
      end
      object EPCH1_BYTE5: TEdit
        Left = 8
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 5
        Text = '0,0'
      end
      object EPCH1_BYTE7: TEdit
        Left = 8
        Top = 52
        Width = 41
        Height = 21
        TabOrder = 6
        Text = '0'
      end
      object EPCH1_BYTE9: TEdit
        Left = 8
        Top = 76
        Width = 41
        Height = 21
        TabOrder = 7
        Text = '0,0'
      end
      object EPCH1_BYTE10: TEdit
        Left = 8
        Top = 100
        Width = 41
        Height = 21
        TabOrder = 8
        Text = '0,0'
      end
      object EPCH1_BYTE13: TEdit
        Left = 344
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 9
        Text = '0,0'
      end
      object EPCH1_BYTE17: TEdit
        Left = 344
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 10
        Text = '0'
      end
      object EPCH1_BYTE23: TEdit
        Left = 344
        Top = 52
        Width = 41
        Height = 21
        TabOrder = 11
        Text = '0'
      end
      object EPCH1_BYTE25: TEdit
        Left = 344
        Top = 76
        Width = 41
        Height = 21
        TabOrder = 12
        Text = '0'
      end
      object EPCH1_BYTE29: TEdit
        Left = 800
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 13
        Text = '0'
      end
      object EPCH1_BYTE39: TEdit
        Left = 800
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 14
        Text = '0'
      end
      object EPCH1_BYTE41: TEdit
        Left = 800
        Top = 52
        Width = 41
        Height = 21
        TabOrder = 15
        Text = '0'
      end
      object EPCH1_BYTE43: TEdit
        Left = 800
        Top = 76
        Width = 41
        Height = 21
        TabOrder = 16
        Text = '0'
      end
    end
    object OTV_KPSN_02h: TTabSheet
      Caption = #1054#1090#1074#1077#1090' '#1050#1055#1057#1053'2 ('#1082#1086#1084#1072#1085#1076#1072' 02h)'
      ImageIndex = 1
      object LPCH2_BYTE3: TLabel
        Left = 56
        Top = 8
        Width = 188
        Height = 13
        Caption = 'Fpllout, '#1060#1040#1055#1063' '#1095#1072#1089#1090#1086#1090#1072' '#1089#1077#1090#1080', '#1043#1094
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE5: TLabel
        Left = 56
        Top = 32
        Width = 256
        Height = 13
        Caption = 'Dout RMS, '#1057#1050#1047' '#1082#1086#1101#1092#1092'. '#1084#1086#1076#1091#1083#1103#1094#1080#1080' '#1064#1048#1052', %'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE7: TLabel
        Left = 56
        Top = 56
        Width = 157
        Height = 13
        Caption = 'Im_set, '#1040#1084#1087#1083#1080#1090#1091#1076#1072' '#1090#1086#1082#1072', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE9: TLabel
        Left = 56
        Top = 80
        Width = 189
        Height = 13
        Caption = 'Te, '#1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1088#1072#1076#1080#1072#1090#1086#1088#1072', '#176#1057
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE10: TLabel
        Left = 56
        Top = 104
        Width = 217
        Height = 13
        Caption = 'Tecu, '#1058#1077#1084#1087#1077#1088#1072#1090#1091#1088#1072' '#1082#1086#1085#1090#1088#1086#1083#1083#1077#1088#1072', '#176#1057
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE13: TLabel
        Left = 392
        Top = 8
        Width = 366
        Height = 13
        Caption = 'Dchop, '#1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090#1072' '#1084#1086#1076#1091#1083#1103#1094#1080#1080' '#1064#1048#1052' '#1090#1086#1088#1084#1086#1079#1085#1086#1075#1086' '#1082#1083#1102#1095#1072', %'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE17: TLabel
        Left = 392
        Top = 32
        Width = 390
        Height = 13
        Caption = 'Id (Ibr_m), '#1057#1088#1077#1076#1085#1080#1081' '#1079#1072' '#1087#1077#1088#1080#1086#1076' '#1064#1048#1052' '#1090#1086#1082' '#1090#1086#1088#1084#1086#1079#1085#1086#1075#1086' '#1088#1077#1079#1080#1089#1090#1086#1088#1072', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE23: TLabel
        Left = 392
        Top = 56
        Width = 395
        Height = 13
        Caption = 'Uac RMS, '#1057#1050#1047' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' '#1089#1086' '#1089#1090#1086#1088#1086#1085#1099' '#1092#1072#1079#1099' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1103', '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE25: TLabel
        Left = 390
        Top = 80
        Width = 253
        Height = 13
        Caption = 'Ia (I2) RMS, '#1057#1050#1047' '#1090#1086#1082#1072' '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1103', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE29: TLabel
        Left = 846
        Top = 8
        Width = 216
        Height = 13
        Caption = 'Udc, '#1053#1072#1087#1088#1103#1078#1077#1085#1080#1077' '#1082#1086#1085#1076#1077#1085#1089#1072#1090#1086#1088#1086#1074', '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE39: TLabel
        Left = 846
        Top = 32
        Width = 297
        Height = 13
        Caption = 'Uac, '#1052#1075#1085#1086#1074#1077#1085#1085#1086#1077' '#1079#1085'-'#1077' '#1085#1072#1087#1088#1103#1078'. '#1087#1077#1088#1074'. '#1086#1073#1084'. (HV), '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE41: TLabel
        Left = 846
        Top = 56
        Width = 213
        Height = 13
        Caption = 'Ia, '#1052#1075#1085#1086#1074#1077#1085#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1090#1086#1082#1072' Ia, '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE43: TLabel
        Left = 846
        Top = 80
        Width = 213
        Height = 13
        Caption = 'Ib, '#1052#1075#1085#1086#1074#1077#1085#1085#1086#1077' '#1079#1085#1072#1095#1077#1085#1080#1077' '#1090#1086#1082#1072' Ib, '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object EPCH2_BYTE3: TEdit
        Left = 8
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 0
        Text = '0,0'
      end
      object EPCH2_BYTE5: TEdit
        Left = 8
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 1
        Text = '0,0'
      end
      object EPCH2_BYTE7: TEdit
        Left = 8
        Top = 52
        Width = 41
        Height = 21
        TabOrder = 2
        Text = '0'
      end
      object EPCH2_BYTE9: TEdit
        Left = 8
        Top = 76
        Width = 41
        Height = 21
        TabOrder = 3
        Text = '0,0'
      end
      object EPCH2_BYTE10: TEdit
        Left = 8
        Top = 100
        Width = 41
        Height = 21
        TabOrder = 4
        Text = '0,0'
      end
      object EPCH2_BYTE13: TEdit
        Left = 344
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 5
        Text = '0,0'
      end
      object EPCH2_BYTE17: TEdit
        Left = 344
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 6
        Text = '0'
      end
      object EPCH2_BYTE23: TEdit
        Left = 344
        Top = 52
        Width = 41
        Height = 21
        TabOrder = 7
        Text = '0'
      end
      object EPCH2_BYTE25: TEdit
        Left = 344
        Top = 76
        Width = 41
        Height = 21
        TabOrder = 8
        Text = '0'
      end
      object EPCH2_BYTE29: TEdit
        Left = 800
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 9
        Text = '0'
      end
      object EPCH2_BYTE39: TEdit
        Left = 800
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 10
        Text = '0'
      end
      object EPCH2_BYTE41: TEdit
        Left = 800
        Top = 52
        Width = 41
        Height = 21
        TabOrder = 11
        Text = '0'
      end
      object EPCH2_BYTE43: TEdit
        Left = 800
        Top = 76
        Width = 41
        Height = 21
        TabOrder = 12
        Text = '0'
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 132
        Width = 329
        Height = 129
        Caption = 'RUNMODE, '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099', '#1084#1083'.'#1073'.'
        TabOrder = 13
        object CB_PCH2_BYTE31: TCheckListBox
          Left = 8
          Top = 16
          Width = 313
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' DISCH_ON, '#1054#1057' '#1087#1088#1080#1085#1091#1076'. '#1088#1072#1079#1088#1103#1076#1072' '#1076#1083#1103' '#1095#1086#1087#1087#1077#1088#1072
            '6'#1088' '#8211' LIM_PLL, '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1079#1072#1076#1072#1085#1080#1103' '#1095#1072#1089#1090#1086#1090#1099' VCO PLL'
            '5'#1088' '#8211' LIM_UDC, '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1056#1053
            '4'#1088' '#8211' LIM_IDQ, '#1086#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1056#1058' D '#1080#1083#1080' Q'
            '3'#1088' '#8211' FAULT, '#1086#1096#1080#1073#1082#1080' '#1074' '#1089#1090#1072#1090#1091#1089#1077
            '2'#1088' '#8211' ENA/nPRE, (1 = '#1088#1072#1073#1086#1090#1072', 0 = '#1086#1078#1080#1076#1072#1085#1080#1077')'
            '1'#1088' '#8211' RUNMODE1, '#1054#1057' '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099
            '0'#1088' '#8211' RUNMODE0, '#1054#1057' '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GroupBox2: TGroupBox
        Left = 344
        Top = 132
        Width = 289
        Height = 129
        Caption = 'STATUS, '#1041#1080#1090#1099' '#1086#1096#1080#1073#1086#1082', '#1084#1083'.'#1073'.'
        TabOrder = 14
        object CB_PCH2_BYTE33: TCheckListBox
          Left = 8
          Top = 16
          Width = 273
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' OVT, '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1077' '#1090#1077#1084#1087#1077#1088#1072#1090#1091#1088#1099
            '6'#1088' '#8211' OVC, '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1077' '#1090#1086#1082#1072' A/B, TTS error'
            '5'#1088' '#8211' TZ6, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( '#1074' '#1088#1077#1079#1077#1088#1074#1077' )'
            '4'#1088' '#8211' TZ5, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( '#1074' '#1088#1077#1079#1077#1088#1074#1077' )'
            '3'#1088' '#8211' TZ4, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( '#1074' '#1088#1077#1079#1077#1088#1074#1077' )'
            '2'#1088' '#8211' TZ3, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( 3 '#1087#1086#1083#1091#1084#1086#1089#1090' )'
            '1'#1088' '#8211' TZ2, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( 2 '#1087#1086#1083#1091#1084#1086#1089#1090' )'
            '0'#1088' '#8211' TZ1, '#1079#1072#1097#1080#1090#1072' '#1076#1088#1072#1081#1074#1077#1088#1072' ( 1 '#1087#1086#1083#1091#1084#1086#1089#1090' )')
          ParentFont = False
          TabOrder = 0
        end
      end
      object GroupBox3: TGroupBox
        Left = 8
        Top = 268
        Width = 329
        Height = 129
        Caption = 'RUNMODE, '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099', '#1089#1090'.'#1073'.'
        TabOrder = 15
        object CB_PCH2_BYTE32: TCheckListBox
          Left = 8
          Top = 16
          Width = 313
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '6'#1088' '#8211' SYNCED, '#1087#1088'. '#1089#1080#1085#1093#1088'. ('#1074#1089#1077#1075#1076#1072' = 1)'
            '5'#1088' '#8211' S_INDELT, '#1087#1088'. '#1089#1080#1085#1093#1088'. ('#1074#1089#1077#1075#1076#1072' = 1)'
            '4'#1088' '#8211' SYNCED_IN, '#1087#1088'. '#1089#1080#1085#1093#1088'. ('#1074#1089#1077#1075#1076#1072' = 1)'
            '3'#1088' '#8211' TTS_ERR, '#1087#1088'. '#1085#1077#1091#1076#1072#1095#1085#1086#1081' '#1087#1086#1087#1099#1090#1082#1072' '#1074#1082#1083#1102#1095#1077#1085#1080#1103
            '2'#1088' '#8211' LOCK, 1 - PLL '#1074' '#1088#1077#1078#1080#1084#1077' '#1079#1072#1093#1074#1072#1090#1072
            '1'#1088' '#8211' SEARCH, 1 - PLL '#1074' '#1088#1077#1078#1080#1084#1077' '#1087#1086#1080#1089#1082#1072
            '0'#1088' '#8211' PRESENT, 1 - '#1087#1088#1080#1079#1085#1072#1082' '#1085#1086#1088#1084#1099' '#1074#1093#1086#1076#1085#1086#1075#1086' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GroupBox4: TGroupBox
        Left = 344
        Top = 268
        Width = 289
        Height = 129
        Caption = 'STATUS, '#1041#1080#1090#1099' '#1086#1096#1080#1073#1086#1082', '#1089#1090'.'#1073'.'
        TabOrder = 16
        object CB_PCH2_BYTE34: TCheckListBox
          Left = 8
          Top = 16
          Width = 273
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' CONFERR, '#1086#1096#1080#1073#1082#1072' '#1082#1086#1085#1092#1080#1075#1091#1088#1072#1094#1080#1080
            '6'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '5'#1088' '#8211' FRAMCRC, '#1086#1096#1080#1073#1082#1072' '#1074' EEPROM'
            '4'#1088' '#8211' I2CNAK, '#1086#1096#1080#1073#1082#1072' '#1085#1072' '#1084#1072#1075'. I2C'
            '3'#1088' '#8211' NO_SYNC, '#1053#1077#1090' '#1089#1080#1085#1093#1088#1086#1087#1072#1082#1077#1090#1072
            '2'#1088' '#8211' PLL_ERR, '#1087#1077#1088#1077#1082#1083'. '#1074' '#1088#1077#1078#1080#1084' '#1089#1090#1072#1073#1080#1083#1080#1079#1072#1094#1080#1080' '#1073#1077#1079' PLL LOCK'
            '1'#1088' '#8211' OVC_BR, '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1077' '#1090#1086#1082#1072' C (chopper)'
            '0'#1088' '#8211' OVV, '#1087#1088#1077#1074#1099#1096#1077#1085#1080#1077' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' DC')
          ParentFont = False
          TabOrder = 0
        end
      end
    end
    object DIAGN_PCH_01h: TTabSheet
      Caption = #1050#1086#1084#1072#1085#1076#1099' '#1091#1087#1088#1072#1074#1083'. '#1055#1063'1'
      ImageIndex = 2
      object LPCH1_BYTE49: TLabel
        Left = 56
        Top = 8
        Width = 204
        Height = 13
        Caption = 'Set1, '#1059#1089#1090#1072#1074#1082#1072' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' Udc, '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE51: TLabel
        Left = 56
        Top = 32
        Width = 369
        Height = 13
        Caption = 'Set2, '#1059#1089#1090#1072#1074#1082#1072' '#1072#1084#1087#1083#1080#1090#1091#1076#1099' '#1090#1086#1082#1072' '#1074#1090#1086#1088#1080#1095#1085#1086#1081' '#1086#1073#1084#1086#1090#1082#1080' (Im_set), '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE55: TLabel
        Left = 488
        Top = 8
        Width = 344
        Height = 13
        Caption = 'Im_min, '#1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1074#1099#1093#1086#1076#1072' '#1088#1077#1075#1091#1083#1103#1090#1086#1088#1072' Udc '#1084#1080#1085#1080#1084#1091#1084', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH1_BYTE57: TLabel
        Left = 488
        Top = 32
        Width = 354
        Height = 13
        Caption = 'Im_max, '#1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1074#1099#1093#1086#1076#1072' '#1088#1077#1075#1091#1083#1103#1090#1086#1088#1072' Udc '#1084#1072#1082#1089#1080#1084#1091#1084', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object GB_PCH1_BYTE47: TGroupBox
        Left = 8
        Top = 60
        Width = 289
        Height = 129
        Caption = 'MODESET, '#1056#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099', '#1084#1083'.'#1073'.'
        TabOrder = 0
        object CB_PCH1_BYTE47: TCheckListBox
          Left = 8
          Top = 16
          Width = 273
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1088#1077#1079#1077#1088#1074
            '6'#1088' - '#1088#1077#1079#1077#1088#1074
            '5'#1088' - '#1088#1077#1079#1077#1088#1074
            '4'#1088' - '#1088#1077#1079#1077#1088#1074
            '3'#1088' - FRS, '#1089#1073#1088#1086#1089' '#1072#1074#1072#1088#1080#1080' ('#1087#1086' '#1092#1088#1086#1085#1090#1091')'
            '2'#1088' - IM_SEL, (1 - '#1087#1088#1103#1084#1086#1077' '#1079#1072#1076#1072#1085#1080#1077' '#1090#1086#1082#1072')'
            '1'#1088' - RUNMODE1, '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099
            '0'#1088' - RUNMODE0, '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH1_BYTE48: TGroupBox
        Left = 304
        Top = 60
        Width = 289
        Height = 129
        Caption = 'MODESET, '#1056#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099', '#1089#1090'.'#1073'.'
        TabOrder = 1
        object CB_PCH1_BYTE48: TCheckListBox
          Left = 8
          Top = 16
          Width = 273
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1088#1077#1079#1077#1088#1074
            '6'#1088' - '#1088#1077#1079#1077#1088#1074
            '5'#1088' - '#1088#1077#1079#1077#1088#1074
            '4'#1088' - '#1088#1077#1079#1077#1088#1074
            '3'#1088' - '#1088#1077#1079#1077#1088#1074
            '2'#1088' - FASTREG, '#1091#1089#1082#1086#1088#1077#1085#1080#1077' '#1088#1077#1075#1091#1083#1103#1090#1086#1088#1072
            '1'#1088' - '#1088#1077#1079#1077#1088#1074
            '0'#1088' - DISCH_ON, '#1079#1072#1088#1103#1076' '#1076#1083#1103' '#1095#1086#1087#1087#1077#1088#1072)
          ParentFont = False
          TabOrder = 0
        end
      end
      object EPCH1_BYTE49: TEdit
        Left = 8
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 2
        Text = '0'
      end
      object EPCH1_BYTE51: TEdit
        Left = 8
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 3
        Text = '0'
      end
      object EPCH1_BYTE55: TEdit
        Left = 440
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 4
        Text = '0'
      end
      object EPCH1_BYTE57: TEdit
        Left = 440
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 5
        Text = '0'
      end
    end
    object DIAGN_PCH_02h: TTabSheet
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' + '#1050#1086#1084#1072#1085#1076#1099' '#1091#1087#1088#1072#1074#1083'. '#1055#1063'2'
      ImageIndex = 3
      object LPCH2_BYTE49: TLabel
        Left = 56
        Top = 8
        Width = 204
        Height = 13
        Caption = 'Set1, '#1059#1089#1090#1072#1074#1082#1072' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1103' Udc, '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE51: TLabel
        Left = 56
        Top = 32
        Width = 369
        Height = 13
        Caption = 'Set2, '#1059#1089#1090#1072#1074#1082#1072' '#1072#1084#1087#1083#1080#1090#1091#1076#1099' '#1090#1086#1082#1072' '#1074#1090#1086#1088#1080#1095#1085#1086#1081' '#1086#1073#1084#1086#1090#1082#1080' (Im_set), '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE55: TLabel
        Left = 488
        Top = 8
        Width = 344
        Height = 13
        Caption = 'Im_min, '#1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1074#1099#1093#1086#1076#1072' '#1088#1077#1075#1091#1083#1103#1090#1086#1088#1072' Udc '#1084#1080#1085#1080#1084#1091#1084', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LPCH2_BYTE57: TLabel
        Left = 488
        Top = 32
        Width = 354
        Height = 13
        Caption = 'Im_max, '#1054#1075#1088#1072#1085#1080#1095#1077#1085#1080#1077' '#1074#1099#1093#1086#1076#1072' '#1088#1077#1075#1091#1083#1103#1090#1086#1088#1072' Udc '#1084#1072#1082#1089#1080#1084#1091#1084', '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object EPCH2_BYTE49: TEdit
        Left = 8
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 0
        Text = '0'
      end
      object EPCH2_BYTE51: TEdit
        Left = 8
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 1
        Text = '0'
      end
      object EPCH2_BYTE55: TEdit
        Left = 440
        Top = 4
        Width = 41
        Height = 21
        TabOrder = 2
        Text = '0'
      end
      object EPCH2_BYTE57: TEdit
        Left = 440
        Top = 28
        Width = 41
        Height = 21
        TabOrder = 3
        Text = '0'
      end
      object GB_PCH2_BYTE48: TGroupBox
        Left = 304
        Top = 60
        Width = 289
        Height = 129
        Caption = 'MODESET, '#1056#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099', '#1089#1090'.'#1073'.'
        TabOrder = 4
        object CB_PCH2_BYTE48: TCheckListBox
          Left = 8
          Top = 16
          Width = 273
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1088#1077#1079#1077#1088#1074
            '6'#1088' - '#1088#1077#1079#1077#1088#1074
            '5'#1088' - '#1088#1077#1079#1077#1088#1074
            '4'#1088' - '#1088#1077#1079#1077#1088#1074
            '3'#1088' - '#1088#1077#1079#1077#1088#1074
            '2'#1088' - FASTREG, '#1091#1089#1082#1086#1088#1077#1085#1080#1077' '#1088#1077#1075#1091#1083#1103#1090#1086#1088#1072
            '1'#1088' - '#1088#1077#1079#1077#1088#1074
            '0'#1088' - DISCH_ON, '#1079#1072#1088#1103#1076' '#1076#1083#1103' '#1095#1086#1087#1087#1077#1088#1072)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH2_BYTE47: TGroupBox
        Left = 8
        Top = 60
        Width = 289
        Height = 129
        Caption = 'MODESET, '#1056#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099', '#1084#1083'.'#1073'.'
        TabOrder = 5
        object CB_PCH2_BYTE47: TCheckListBox
          Left = 8
          Top = 16
          Width = 273
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1088#1077#1079#1077#1088#1074
            '6'#1088' - '#1088#1077#1079#1077#1088#1074
            '5'#1088' - '#1088#1077#1079#1077#1088#1074
            '4'#1088' - '#1088#1077#1079#1077#1088#1074
            '3'#1088' - FRS, '#1089#1073#1088#1086#1089' '#1072#1074#1072#1088#1080#1080' ('#1087#1086' '#1092#1088#1086#1085#1090#1091')'
            '2'#1088' - IM_SEL, (1 - '#1087#1088#1103#1084#1086#1077' '#1079#1072#1076#1072#1085#1080#1077' '#1090#1086#1082#1072')'
            '1'#1088' - RUNMODE1, '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099
            '0'#1088' - RUNMODE0, '#1088#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH2_BYTE45: TGroupBox
        Left = 8
        Top = 204
        Width = 505
        Height = 129
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1055#1063'2. NPRM, '#1084#1083'.'#1073
        TabOrder = 6
        object CB_PCH2_BYTE45: TCheckListBox
          Left = 8
          Top = 16
          Width = 489
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' '#8211' DCDC, '#1088#1077#1078#1080#1084' DC/DC '#1087#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1090#1077#1083#1103' ('#1089#1088#1077#1076#1085#1080#1081' '#1087#1088#1080#1086#1088#1080#1090#1077#1090')'
            
              '6'#1088' '#8211' PHASED, 1 = '#1095#1077#1088#1077#1076#1086#1074#1072#1085#1080#1077' '#1092#1072#1079' DC/DC, 0 = '#1089#1080#1085#1093#1088#1086#1085#1085#1072#1103' '#1088#1072#1073#1086#1090#1072' '#1092#1072 +
              #1079' DC/DC'
            '5'#1088' '#8211' DC_DIR, '#1074#1099#1073#1086#1088' '#1054#1057' DC (1='#1087#1086#1085#1080#1078#1077#1085#1080#1077'/Uout, 0='#1087#1086#1074#1099#1096#1077#1085#1080#1077'/Udc)'
            '4'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '3'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '2'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '1'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '0'#1088' '#8211' '#1088#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH2_BYTE46: TGroupBox
        Left = 520
        Top = 204
        Width = 553
        Height = 129
        Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1055#1063'2. NPRM, '#1089#1090'.'#1073
        TabOrder = 7
        object CB_PCH2_BYTE46: TCheckListBox
          Left = 8
          Top = 16
          Width = 537
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            
              '7'#1088' '#8211' DIRECT, '#1074#1082#1083#1102#1095#1077#1085#1080#1077' '#1074#1077#1088#1093#1085#1077#1075#1086' '#1082#1083#1102#1095#1072' 1 '#1087#1086#1083#1091#1084#1086#1089#1090#1072' '#1080' '#1085#1080#1078#1085#1077#1075#1086' '#1082#1083#1102#1095 +
              #1072' 2 '#1087#1086#1083#1091#1084#1086#1089#1090#1072' '
            '6'#1088' '#8211' EXCIT, '#1056#1077#1078#1080#1084' '#1074#1086#1079#1073#1091#1078#1076#1077#1085#1080#1103' '#1090#1088#1072#1085#1089#1092#1086#1088#1084#1072#1090#1086#1088#1072' '#1085#1072' '#1074#1099#1089#1086#1082#1086#1081' '#1095#1072#1089#1090#1086#1090#1077' '
            
              '5'#1088' '#8211' 3PH, 1 = '#1074#1099#1073#1086#1088' '#1088#1077#1078#1080#1084#1072' '#1090#1088#1077#1093#1092#1072#1079#1085#1086#1075#1086' '#1082#1086#1088#1088#1077#1082#1090#1086#1088#1072' '#1084#1086#1097#1085#1086#1089#1090#1080'/'#1082#1086#1085#1074#1077 +
              #1088#1090#1086#1088#1072
            '4'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            
              '3'#1088' '#8211' DESKEW, 1 = '#1074#1099#1095#1080#1090#1072#1085#1080#1077' '#1087#1086#1089#1090#1086#1103#1085#1085#1086#1081' '#1089#1086#1089#1090'. '#1088#1072#1073#1086#1095#1077#1075#1086' '#1090#1086#1082#1072' '#1079#1072' '#1087#1088#1077 +
              #1076'. '#1087#1077#1088#1080#1086#1076' '#1089#1077#1090#1080
            '2'#1088' '#8211' '#1088#1077#1079#1077#1088#1074
            '1'#1088' '#8211' N_CIR, 1 = '#1079#1072#1076#1077#1088#1078#1082#1072' IQ 4 '#1090#1086#1095#1082#1080', 0 = '#1079#1072#1076#1077#1088#1078#1082#1072' IQ 2 '#1090#1086#1095#1082#1080
            '0'#1088' '#8211' I2_MEAN, 1 = '#1091#1089#1088#1077#1076#1085#1077#1085#1080#1077' '#1088#1072#1073#1086#1095#1077#1075#1086' '#1090#1086#1082#1072' '#1087#1086' 9 '#1090#1086#1095#1082#1072#1084)
          ParentFont = False
          TabOrder = 0
        end
      end
    end
    object INF_BVS_AND_BUK: TTabSheet
      Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1041#1042#1057'1,2 + '#1041#1059#1050'1'
      ImageIndex = 4
      object LBUK4: TLabel
        Left = 448
        Top = 453
        Width = 38
        Height = 16
        Caption = #1041#1059#1050'4'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 744
        Top = 453
        Width = 202
        Height = 16
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077' '#1087#1086' '#1082#1086#1076#1072#1084' '#1041#1059#1050':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LBUK1: TLabel
        Left = 480
        Top = 5
        Width = 38
        Height = 16
        Caption = #1041#1059#1050'1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 792
        Top = 5
        Width = 202
        Height = 16
        Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077' '#1087#1086' '#1082#1086#1076#1072#1084' '#1041#1059#1050':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clMaroon
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LBVS1: TLabel
        Left = 8
        Top = 5
        Width = 109
        Height = 16
        Caption = #1041#1042#1057'1 ('#1082#1072#1085#1072#1083' 1)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
      end
      object LBVS2: TLabel
        Left = 8
        Top = 197
        Width = 109
        Height = 16
        Caption = #1041#1042#1057'1 ('#1082#1072#1085#1072#1083' 2)'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
      end
      object LBUK2: TLabel
        Left = 480
        Top = 197
        Width = 38
        Height = 16
        Caption = #1041#1059#1050'2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold, fsUnderline]
        ParentFont = False
      end
      object GB_PCH2_BYTE59: TGroupBox
        Left = 8
        Top = 28
        Width = 225
        Height = 129
        Caption = #1041#1042#1057'1 ('#1082'1), '#1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1074#1093#1086#1076#1086#1074' 1-8 '#1041#1042#1057
        TabOrder = 0
        object CB_PCH2_BYTE59: TCheckListBox
          Left = 8
          Top = 16
          Width = 209
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1088#1077#1079#1077#1088#1074
            '6'#1088' - '#1088#1077#1079#1077#1088#1074
            '5'#1088' - '#1088#1077#1079#1077#1088#1074
            '4'#1088' - '#1088#1077#1079#1077#1088#1074
            '3'#1088' - '#1088#1077#1079#1077#1088#1074
            '2'#1088' - '#1056#1072#1079#1088#1077#1096#1077#1085#1080#1077' '#1088#1072#1073#1086#1090#1099
            '1'#1088' - '#1088#1077#1079#1077#1088#1074
            '0'#1088' - '#1088#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH2_BYTE60: TGroupBox
        Left = 240
        Top = 28
        Width = 217
        Height = 129
        Caption = #1041#1042#1057'1 ('#1082'1), '#1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1074#1093#1086#1076#1086#1074' 9-16 '#1041#1042#1057
        TabOrder = 1
        object CB_PCH2_BYTE60: TCheckListBox
          Left = 8
          Top = 16
          Width = 169
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1050#1052'4'
            '6'#1088' - '#1050#1052'3'
            '5'#1088' - '#1050#1052'2'
            '4'#1088' - '#1050#1052'1'
            '3'#1088' - '#1088#1077#1079#1077#1088#1074
            '2'#1088' - '#1088#1077#1079#1077#1088#1074
            '1'#1088' - '#1088#1077#1079#1077#1088#1074
            '0'#1088' - '#1088#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH2_BYTE61: TGroupBox
        Left = 8
        Top = 220
        Width = 225
        Height = 129
        Caption = #1041#1042#1057'1 ('#1082'2), '#1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1074#1093#1086#1076#1086#1074' 1-8 '#1041#1042#1057
        TabOrder = 2
        object CB_PCH2_BYTE61: TCheckListBox
          Left = 8
          Top = 16
          Width = 201
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1088#1077#1079#1077#1088#1074
            '6'#1088' - '#1088#1077#1079#1077#1088#1074
            '5'#1088' - '#1088#1077#1079#1077#1088#1074
            '4'#1088' - '#1088#1077#1079#1077#1088#1074
            '3'#1088' - '#1088#1077#1079#1077#1088#1074
            '2'#1088' - '#1056#1072#1079#1088#1077#1096#1077#1085#1080#1077' '#1088#1072#1073#1086#1090#1099
            '1'#1088' - '#1088#1077#1079#1077#1088#1074
            '0'#1088' - '#1088#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH2_BYTE62: TGroupBox
        Left = 240
        Top = 220
        Width = 217
        Height = 129
        Caption = #1041#1042#1057'1 ('#1082'2), '#1057#1086#1089#1090#1086#1103#1085#1080#1077' '#1074#1093#1086#1076#1086#1074' 9-16 '#1041#1042#1057
        TabOrder = 3
        object CB_PCH2_BYTE62: TCheckListBox
          Left = 8
          Top = 16
          Width = 193
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1050#1052'4'
            '6'#1088' - '#1050#1052'3'
            '5'#1088' - '#1050#1052'2'
            '4'#1088' - '#1050#1052'1'
            '3'#1088' - '#1088#1077#1079#1077#1088#1074
            '2'#1088' - '#1088#1077#1079#1077#1088#1074
            '1'#1088' - '#1088#1077#1079#1077#1088#1074
            '0'#1088' - '#1088#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH2_BYTE63: TGroupBox
        Left = 480
        Top = 28
        Width = 161
        Height = 129
        Caption = #1050#1086#1084#1072#1085#1076#1099' '#1041#1059#1050'1'
        TabOrder = 4
        object CB_PCH2_BYTE63: TCheckListBox
          Left = 8
          Top = 16
          Width = 129
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1088#1077#1079#1077#1088#1074
            '6'#1088' - '#1088#1077#1079#1077#1088#1074
            '5'#1088' - '#1042#1082#1083'. '#1050#1052'4'
            '4'#1088' - '#1042#1082#1083'. '#1050#1052'3'
            '3'#1088' - '#1042#1082#1083'. '#1050#1052'2'
            '2'#1088' - '#1042#1082#1083'. '#1050#1052'1'
            '1'#1088' - '#1088#1077#1079#1077#1088#1074
            '0'#1088' - '#1088#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_PCH2_BYTE64: TGroupBox
        Left = 480
        Top = 220
        Width = 161
        Height = 129
        Caption = #1050#1086#1084#1072#1085#1076#1099' '#1041#1059#1050'2'
        TabOrder = 5
        object CB_PCH2_BYTE64: TCheckListBox
          Left = 8
          Top = 16
          Width = 145
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1088#1077#1079#1077#1088#1074
            '6'#1088' - '#1088#1077#1079#1077#1088#1074
            '5'#1088' - '#1042#1082#1083'. '#1050#1052'4'
            '4'#1088' - '#1042#1082#1083'. '#1050#1052'3'
            '3'#1088' - '#1042#1082#1083'. '#1050#1052'2'
            '2'#1088' - '#1042#1082#1083'. '#1050#1052'1'
            '1'#1088' - '#1088#1077#1079#1077#1088#1074
            '0'#1088' - '#1088#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_BUK1: TGroupBox
        Left = 648
        Top = 25
        Width = 121
        Height = 180
        Caption = #1050#1086#1076#1099' '#1085#1077#1080#1089#1087#1088#1072#1074'.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
        object VLBUK1_KEY1: TLabel
          Left = 88
          Top = 18
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK1_KEY2: TLabel
          Left = 88
          Top = 38
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK1_KEY3: TLabel
          Left = 88
          Top = 58
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK1_KEY4: TLabel
          Left = 88
          Top = 78
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK1_KEY5: TLabel
          Left = 88
          Top = 98
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK1_KEY6: TLabel
          Left = 88
          Top = 118
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK1_KEY7: TLabel
          Left = 88
          Top = 138
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK1_KEY8: TLabel
          Left = 88
          Top = 158
          Width = 6
          Height = 13
          Caption = '0'
        end
        object LBUK1_KEY8: TLabel
          Left = 11
          Top = 158
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 8'
        end
        object LBUK1_KEY7: TLabel
          Left = 11
          Top = 138
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 7'
        end
        object LBUK1_KEY6: TLabel
          Left = 11
          Top = 118
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 6'
        end
        object LBUK1_KEY5: TLabel
          Left = 11
          Top = 98
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 5'
        end
        object LBUK1_KEY4: TLabel
          Left = 11
          Top = 78
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 4'
        end
        object LBUK1_KEY3: TLabel
          Left = 11
          Top = 58
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 3'
        end
        object LBUK1_KEY1: TLabel
          Left = 11
          Top = 18
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 1'
        end
        object LBUK1_KEY2: TLabel
          Left = 11
          Top = 38
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 2'
        end
      end
      object Memo1: TMemo
        Left = 792
        Top = 28
        Width = 233
        Height = 153
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Lines.Strings = (
          #1047#1085#1072#1095#1077#1085#1080#1103' '#1082#1086#1076#1086#1074' '#1085#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1077#1081' '
          #1041#1059#1050' '#1084#1086#1075#1091#1090' '#1073#1099#1090#1100' '#1089#1083#1077#1076#1091#1102#1097#1080#1084#1080':'
          '0 - '#1085#1077#1090' '#1085#1077#1080#1089#1087#1088#1072#1074#1085#1086#1089#1090#1077#1081';'
          '1 - '#1086#1073#1088#1099#1074' '#1085#1072#1075#1088#1091#1079#1082#1080';'
          '2 - '#1087#1077#1088#1077#1075#1088#1091#1079#1082#1072';'
          '3 - '#1086#1073#1088#1099#1074' '#1082#1083#1102#1095#1072';'
          '4 - '#1082#1086#1088#1086#1090#1082#1086#1077' '#1079#1072#1084#1099#1082#1072#1085#1080#1077' '#1085#1072#1075#1088#1091#1079#1082#1080';'
          '5 - '#1082#1086#1088#1086#1090#1082#1086#1077' '#1079#1072#1084#1099#1082#1072#1085#1080#1077' '#1082#1083#1102#1095#1072' '#1080#1083#1080' '
          #1076#1080#1086#1076#1072'.')
        ParentFont = False
        TabOrder = 7
      end
      object GB_BUK2: TGroupBox
        Left = 648
        Top = 217
        Width = 121
        Height = 180
        Caption = #1050#1086#1076#1099' '#1085#1077#1080#1089#1087#1088#1072#1074'.'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 8
        object VLBUK2_KEY1: TLabel
          Left = 88
          Top = 18
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK2_KEY2: TLabel
          Left = 88
          Top = 38
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK2_KEY3: TLabel
          Left = 88
          Top = 58
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK2_KEY4: TLabel
          Left = 88
          Top = 78
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK2_KEY5: TLabel
          Left = 88
          Top = 98
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK2_KEY6: TLabel
          Left = 88
          Top = 118
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK2_KEY7: TLabel
          Left = 88
          Top = 138
          Width = 6
          Height = 13
          Caption = '0'
        end
        object VLBUK2_KEY8: TLabel
          Left = 88
          Top = 158
          Width = 6
          Height = 13
          Caption = '0'
        end
        object LBUK2_KEY8: TLabel
          Left = 11
          Top = 158
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 8'
        end
        object LBUK2_KEY7: TLabel
          Left = 11
          Top = 138
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 7'
        end
        object LBUK2_KEY6: TLabel
          Left = 11
          Top = 118
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 6'
        end
        object LBUK2_KEY5: TLabel
          Left = 11
          Top = 98
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 5'
        end
        object LBUK2_KEY4: TLabel
          Left = 11
          Top = 78
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 4'
        end
        object LBUK2_KEY3: TLabel
          Left = 11
          Top = 58
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 3'
        end
        object LBUK2_KEY1: TLabel
          Left = 11
          Top = 18
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 1'
        end
        object LBUK2_KEY2: TLabel
          Left = 11
          Top = 38
          Width = 35
          Height = 13
          Caption = #1050#1083#1102#1095' 2'
        end
      end
    end
  end
  object PC_DIAGN_M1: TPageControl
    Left = 360
    Top = 8
    Width = 481
    Height = 313
    ActivePage = TabSheet3
    TabIndex = 0
    TabOrder = 9
    object TabSheet3: TTabSheet
      Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1089#1074#1103#1079#1080' '#1087#1086'  '#1052'1'
      object GB_RPD_BYTE59: TGroupBox
        Left = 0
        Top = 4
        Width = 209
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1089#1074#1103#1079#1080' '#1087#1086' '#1052'1 ('#1073#1072#1081#1090' 59)'
        TabOrder = 0
        object CB_RPD_BYTE59: TCheckListBox
          Left = 8
          Top = 16
          Width = 185
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1053#1057' '#1089' '#1041#1042#1057' ('#1082#1072#1085#1072#1083' 1)'
            '6'#1088' - '#1053#1057' '#1089' '#1055#1063'2 ('#1079#1072#1087#1088#1086#1089' 05)'
            '5'#1088' - '#1053#1057' '#1089' '#1055#1063'2 ('#1079#1072#1087#1088#1086#1089' 03)'
            '4'#1088' - '#1053#1057' '#1089' '#1055#1063'1 ('#1079#1072#1087#1088#1086#1089' 05)'
            '3'#1088' - '#1053#1057' '#1089' '#1055#1063'1 ('#1079#1072#1087#1088#1086#1089' 03)'
            '2'#1088' - '#1053#1057' '#1089' '#1041#1059#1050' ('#1082#1072#1085#1072#1083' 2)'
            '1'#1088' - '#1053#1057' '#1089' '#1041#1059#1050' ('#1082#1072#1085#1072#1083' 1)'
            '0'#1088' - '#1053#1057' '#1089' '#1041#1059#1050' ('#1082#1072#1085#1072#1083' 2)')
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_RPD_BYTE60: TGroupBox
        Left = 216
        Top = 4
        Width = 249
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1089#1074#1103#1079#1080' '#1087#1086' '#1052'1 '#1074' 1 '#1094#1080#1082#1083#1077' ('#1073#1072#1081#1090' 60)'
        TabOrder = 1
        object CB_RPD_BYTE60: TCheckListBox
          Left = 8
          Top = 16
          Width = 233
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1053#1057' '#1089' '#1041#1042#1057' ('#1082#1072#1085#1072#1083' 1) '#1074' 1 '#1094#1080#1082#1083#1077
            '6'#1088' - '#1053#1057' '#1089' '#1055#1063'2 ('#1079#1072#1087#1088#1086#1089' 05) '#1074' 1 '#1094#1080#1082#1083#1077
            '5'#1088' - '#1053#1057' '#1089' '#1055#1063'2 ('#1079#1072#1087#1088#1086#1089' 03) '#1074' 1 '#1094#1080#1082#1083#1077
            '4'#1088' - '#1053#1057' '#1089' '#1055#1063'1 ('#1079#1072#1087#1088#1086#1089' 05) '#1074' 1 '#1094#1080#1082#1083#1077
            '3'#1088' - '#1053#1057' '#1089' '#1055#1063'1 ('#1079#1072#1087#1088#1086#1089' 03) '#1074' 1 '#1094#1080#1082#1083#1077
            '2'#1088' - '#1053#1057' '#1089' '#1041#1059#1050' ('#1082#1072#1085#1072#1083' 2) '#1074' 1 '#1094#1080#1082#1083#1077
            '1'#1088' - '#1053#1057' '#1089' '#1041#1059#1050' ('#1082#1072#1085#1072#1083' 1) '#1074' 1 '#1094#1080#1082#1083#1077
            '0'#1088' - '#1053#1057' '#1089' '#1041#1059#1050' ('#1082#1072#1085#1072#1083' 2) '#1074' 1 '#1094#1080#1082#1083#1077)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_RPD_BYTE61: TGroupBox
        Left = 0
        Top = 140
        Width = 209
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1089#1074#1103#1079#1080' '#1087#1086' '#1052'1 ('#1073#1072#1081#1090' 61)'
        TabOrder = 2
        object CB_RPD_BYTE61: TCheckListBox
          Left = 8
          Top = 16
          Width = 185
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1053#1057' '#1089' '#1055#1063'2 (APPLY 05)'
            '6'#1088' - '#1053#1057' '#1089' '#1055#1063'1 (APPLY 05)'
            '5'#1088' - '#1053#1057' '#1089' '#1055#1063'2 (NPRM 05)'
            '4'#1088' - '#1053#1057' '#1089' '#1055#1063'1 (NPRM 05)'
            '3'#1088' - '#1053#1057' '#1089' '#1055#1063'2 (APPLY 04)'
            '2'#1088' - '#1053#1057' '#1089' '#1055#1063'1 (APPLY 04)'
            '1'#1088' - '#1053#1057' '#1089' '#1055#1063'2 (NPRM 04)'
            '0'#1088' - '#1053#1057' '#1089' '#1055#1063'1 (NPRM 04)')
          ParentFont = False
          TabOrder = 0
        end
      end
      object GB_RPD_BYTE62: TGroupBox
        Left = 216
        Top = 140
        Width = 249
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1089#1074#1103#1079#1080' '#1087#1086' '#1052'1 '#1074' 1 '#1094#1080#1082#1083#1077' ('#1073#1072#1081#1090' 62)'
        TabOrder = 3
        object CB_RPD_BYTE62: TCheckListBox
          Left = 8
          Top = 16
          Width = 233
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1053#1057' '#1089' '#1055#1063'2 (APPLY 05) '#1074' 1 '#1094#1080#1082#1083#1077' '
            '6'#1088' - '#1053#1057' '#1089' '#1055#1063'1 (APPLY 05) '#1074' 1 '#1094#1080#1082#1083#1077' '
            '5'#1088' - '#1053#1057' '#1089' '#1055#1063'2 (NPRM 05) '#1074' 1 '#1094#1080#1082#1083#1077' '
            '4'#1088' - '#1053#1057' '#1089' '#1055#1063'1 (NPRM 05) '#1074' 1 '#1094#1080#1082#1083#1077' '
            '3'#1088' - '#1053#1057' '#1089' '#1055#1063'2 (APPLY 04) '#1074' 1 '#1094#1080#1082#1083#1077' '
            '2'#1088' - '#1053#1057' '#1089' '#1055#1063'1 (APPLY 04) '#1074' 1 '#1094#1080#1082#1083#1077' '
            '1'#1088' - '#1053#1057' '#1089' '#1055#1063'2 (NPRM 04) '#1074' 1 '#1094#1080#1082#1083#1077' '
            '0'#1088' - '#1053#1057' '#1089' '#1055#1063'1 (NPRM 04) '#1074' 1 '#1094#1080#1082#1083#1077' ')
          ParentFont = False
          TabOrder = 0
        end
      end
    end
  end
  object B_SHOW_RXTX: TButton
    Left = 736
    Top = 328
    Width = 105
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1086#1073#1084#1077#1085
    TabOrder = 10
    OnClick = B_SHOW_RXTXClick
  end
end
